"""The AI proxy (decomp_portal_server.ai_call) without network: request shapes, retries, errors and key hygiene."""
import json
import urllib.error

import pytest

import conftest  # noqa: F401  (puts tools/ on the path)


@pytest.fixture()
def S(monkeypatch):
    import importlib, sys
    sys.path.insert(0, str(conftest.PORTAL))
    mod = importlib.import_module("decomp_portal_server")
    return mod


def fake_http(calls, answers):
    def _http_json(url, body, headers, timeout=180):
        calls.append({"url": url, "body": json.loads(json.dumps(body)) if body is not None else None,
                      "headers": dict(headers), "timeout": timeout})
        st, j = answers.pop(0)
        return st, j, json.dumps(j)
    return _http_json


def chat(text, model="m", **extra):
    msg = {"content": text, **extra.pop("message", {})}
    return {"model": model, "choices": [{"message": msg, **extra}]}


def test_openai_reasoning_models_get_no_temperature(S, monkeypatch):
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [(200, chat("int f() { return 1; }", "gpt-6.1-sol"))]))
    res = S.ai_call({"provider": "openai", "api_key": "sk-test", "model": "gpt-6.1-sol", "prompt": "p"})
    assert res == {"ok": True, "reply": "int f() { return 1; }", "used_model": "gpt-6.1-sol"}
    assert len(calls) == 1 and "temperature" not in calls[0]["body"]
    assert calls[0]["url"] == "https://api.openai.com/v1/chat/completions"
    assert calls[0]["headers"]["Authorization"] == "Bearer sk-test"
    assert calls[0]["body"]["messages"][0] == {"role": "system", "content": S.SYSTEM_PROMPT}
    for m in ("o3", "gpt-5.6-terra", "gpt-6-astra", "openai/gpt-6-luna", "~openai/gpt-6.1-sol"):
        assert S._default_temperature_only(m), m
    for m in ("deepseek-chat", "llama-3.3-70b", "qwen2.5-coder:32b", "openrouter/auto"):
        assert not S._default_temperature_only(m), m


def test_other_models_retry_without_temperature_when_refused(S, monkeypatch):
    calls = []
    answers = [(400, {"error": {"message": "Unsupported value: 'temperature' does not support 0.2 with this model."}}),
               (200, chat("ok", "deepseek-chat"))]
    monkeypatch.setattr(S, "_http_json", fake_http(calls, answers))
    res = S.ai_call({"provider": "custom_api", "api_key": "k", "model": "deepseek-chat", "prompt": "p",
                     "custom_url": "https://api.deepseek.com/v1"})
    assert res["ok"] and res["reply"] == "ok"
    assert calls[0]["body"]["temperature"] == 0.2 and "temperature" not in calls[1]["body"]
    assert calls[0]["url"] == "https://api.deepseek.com/v1/chat/completions"     # base URL completed


def test_custom_urls(S):
    assert S._chat_url("https://api.example.com/v1") == "https://api.example.com/v1/chat/completions"
    assert S._chat_url("https://api.example.com/v1/") == "https://api.example.com/v1/chat/completions"
    assert S._chat_url("https://x.io/openai/v1/chat/completions") == "https://x.io/openai/v1/chat/completions"
    assert S._chat_url("http://127.0.0.1:1234") == "http://127.0.0.1:1234/v1/chat/completions"


def test_custom_url_works_without_a_key(S, monkeypatch):
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [(200, chat("ok"))]))
    res = S.ai_call({"provider": "custom_api", "model": "local", "prompt": "p", "custom_url": "http://127.0.0.1:1234/v1"})
    assert res["ok"] and "Authorization" not in calls[0]["headers"]


def test_anthropic_uses_the_current_api_version_without_temperature(S, monkeypatch):
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [
        (200, {"model": "claude-sonnet-5-5", "stop_reason": "end_turn", "content": [{"type": "text", "text": "ok"}]})]))
    res = S.ai_call({"provider": "anthropic", "api_key": "k", "model": "claude-sonnet-5-5", "prompt": "p"})
    assert res == {"ok": True, "reply": "ok", "used_model": "claude-sonnet-5-5"}
    body, hdr = calls[0]["body"], calls[0]["headers"]
    assert hdr["x-api-key"] == "k" and hdr["anthropic-version"] == "2026-10-21"
    assert not {"temperature", "top_p", "top_k"} & set(body) and body["system"] == S.SYSTEM_PROMPT
    assert body["max_tokens"] >= 32000                       # thinking counts toward it
    assert body["thinking"] == {"type": "adaptive"} and body["output_config"] == {"effort": "high"}


def test_anthropic_falls_back_to_the_old_version_if_needed(S, monkeypatch):
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [
        (400, {"error": {"message": "anthropic-version: unknown version"}}),
        (200, {"content": [{"type": "text", "text": "ok"}]})]))
    res = S.ai_call({"provider": "anthropic", "api_key": "k", "model": "claude-haiku-5-5", "prompt": "p"})
    assert res["ok"] and calls[1]["headers"]["anthropic-version"] == "2023-06-01"


def test_gemini_sends_no_temperature_and_skips_thoughts(S, monkeypatch):
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [
        (200, {"candidates": [{"content": {"parts": [{"text": "thinking...", "thought": True}, {"text": "hi"}]}}]})]))
    res = S.ai_call({"provider": "gemini", "api_key": "g", "model": "gemini-3.8-flash", "prompt": "p"})
    assert res == {"ok": True, "reply": "hi", "used_model": "gemini-3.8-flash"}
    assert calls[0]["body"]["generationConfig"] == {"thinkingConfig": {"thinkingLevel": "high"}}   # no temperature
    assert calls[0]["url"].endswith("gemini-3.8-flash:generateContent")
    assert calls[0]["headers"]["x-goog-api-key"] == "g" and "key=" not in calls[0]["url"]


def test_gemini_replaces_a_retired_model(S, monkeypatch):
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [
        (404, {"error": {"message": "models/gemini-old is not found"}}),
        (200, {"models": [{"name": "models/gemini-3.8-flash", "supportedGenerationMethods": ["generateContent"]},
                          {"name": "models/gemini-3.1-flash-tts", "supportedGenerationMethods": ["generateContent"]}]}),
        (200, {"candidates": [{"content": {"parts": [{"text": "ok"}]}}]})]))
    res = S.ai_call({"provider": "gemini", "api_key": "g", "model": "gemini-old", "prompt": "p"})
    assert res == {"ok": True, "reply": "ok", "used_model": "gemini-3.8-flash"}


@pytest.mark.parametrize("provider,answer,needle", [
    ("openai", chat(None, message={"refusal": "I can't help"}), "declined"),
    ("openai", chat("", finish_reason="length"), "ran out of output"),
    ("anthropic", {"content": [], "stop_reason": "max_tokens"}, "ran out of output"),
    ("anthropic", {"content": [], "stop_reason": "refusal"}, "declined"),
    ("gemini", {"candidates": [{"finishReason": "SAFETY", "content": {}}]}, "declined"),
    ("gemini", {"promptFeedback": {"blockReason": "PROHIBITED_CONTENT"}}, "declined"),
])
def test_an_empty_answer_is_an_error_that_says_why(S, monkeypatch, provider, answer, needle):
    monkeypatch.setattr(S, "_http_json", fake_http([], [(200, answer)]))
    res = S.ai_call({"provider": provider, "api_key": "k", "model": "m", "prompt": "p"})
    assert not res["ok"] and needle in res["error"]


@pytest.mark.parametrize("status,needle", [(401, "rejected"), (429, "Rate limit"), (404, "Model not found"),
                                           (503, "provider had a problem")])
def test_http_errors_are_explained(S, monkeypatch, status, needle):
    monkeypatch.setattr(S, "_http_json", fake_http([], [(status, {"error": "x"})]))
    res = S.ai_call({"provider": "argon", "api_key": "k", "model": "openrouter/auto", "prompt": "p"})
    assert not res["ok"] and needle in res["error"] and f"HTTP {status}" in res["error"]


def test_gemini_bad_key_is_explained(S, monkeypatch):
    monkeypatch.setattr(S, "_http_json", fake_http([], [(400, {"error": {"message": "API key not valid. Please pass a valid API key."}})]))
    res = S.ai_call({"provider": "gemini", "api_key": "k", "model": "gemini-3.8-flash", "prompt": "p"})
    assert "rejected" in res["error"]


def test_errors_never_include_the_key(S, monkeypatch):
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [(401, {"error": "bad key sk-secret-999"})]))
    res = S.ai_call({"provider": "openai", "api_key": "sk-secret-999", "model": "gpt-6-luna", "prompt": "p"})
    assert not res["ok"] and "sk-secret-999" not in res["error"] and "***" in res["error"]

    def boom(*a, **k):
        raise ValueError("weird failure with sk-secret-999 inside")
    monkeypatch.setattr(S, "_http_json", boom)
    res = S.ai_call({"provider": "openai", "api_key": "sk-secret-999", "model": "gpt-6-luna", "prompt": "p"})
    assert "sk-secret-999" not in res["error"]


def test_the_connection_test_is_small(S, monkeypatch):
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [(200, chat("OK"))]))
    res = S.ai_call({"provider": "openai", "api_key": "k", "model": "gpt-6-luna", "prompt": "Ping", "is_test": True})
    assert res["ok"]
    assert calls[0]["body"]["messages"] == [{"role": "user", "content": S.TEST_PROMPT}]   # no long system prompt


def test_unreachable_providers(S, monkeypatch):
    def refused(*a, **k):
        raise urllib.error.URLError(ConnectionRefusedError(111, "Connection refused"))
    monkeypatch.setattr(S, "_http_json", refused)
    res = S.ai_call({"provider": "ollama", "model": "qwen2.5-coder:14b", "prompt": "p"})
    assert "ollama serve" in res["error"]

    def slow(*a, **k):
        raise urllib.error.URLError(TimeoutError("timed out"))
    monkeypatch.setattr(S, "_http_json", slow)
    res = S.ai_call({"provider": "anthropic", "api_key": "k", "model": "claude-opus-5-5", "prompt": "p"})
    assert "took too long" in res["error"]


def test_ollama_missing_model_and_timeout(S, monkeypatch):
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [(404, {"error": "model 'x' not found"})]))
    res = S.ai_call({"provider": "ollama", "model": "x", "prompt": "p"})
    assert "ollama pull x" in res["error"] and calls[0]["timeout"] >= 600


def test_input_checks(S):
    assert "API key" in S.ai_call({"provider": "gemini", "prompt": "p"})["error"]
    assert "Unknown provider" in S.ai_call({"provider": "x", "api_key": "k", "prompt": "p"})["error"]
    assert "Empty prompt" in S.ai_call({"provider": "openai", "api_key": "k"})["error"]
    assert "http" in S.ai_call({"provider": "custom_api", "api_key": "k", "prompt": "p", "custom_url": "file:///x"})["error"]
    assert "Pick a model" in S.ai_call({"provider": "openai", "api_key": "k", "prompt": "p"})["error"]


# --- High reasoning: every provider is asked for it, and a model that refuses it is asked again without ---------

def test_every_provider_asks_for_high_reasoning(S, monkeypatch):
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [(200, chat("ok"))] * 3 + [(200, {"message": {"content": "ok"}})] * 2))
    S.ai_call({"provider": "openai", "api_key": "k", "model": "gpt-6-astra", "prompt": "p"})
    S.ai_call({"provider": "argon", "api_key": "k", "model": "anthropic/claude-fable-5.2", "prompt": "p"})
    S.ai_call({"provider": "custom_api", "api_key": "k", "model": "deepseek-reasoner", "prompt": "p",
               "custom_url": "https://api.deepseek.com/v1"})
    S.ai_call({"provider": "ollama", "model": "gpt-oss:20b", "prompt": "p"})
    S.ai_call({"provider": "ollama", "model": "qwen3-coder:30b", "prompt": "p"})
    assert calls[0]["body"]["reasoning_effort"] == "high"
    assert calls[1]["body"]["reasoning"] == {"effort": "high"} and calls[1]["body"]["model"] == "anthropic/claude-fable-5.2"
    assert calls[2]["body"]["reasoning_effort"] == "high"
    assert calls[3]["body"]["think"] == "high" and calls[4]["body"]["think"] is True
    assert S.REASONING == "high"


def test_old_openai_models_get_no_reasoning_effort(S, monkeypatch):
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [(200, chat("ok", "gpt-4.1"))]))
    S.ai_call({"provider": "openai", "api_key": "k", "model": "gpt-4.1", "prompt": "p"})
    assert "reasoning_effort" not in calls[0]["body"]


@pytest.mark.parametrize("provider,model,field,refusal,ok_answer", [
    ("custom_api", "llama-3.3-70b", "reasoning_effort", {"error": {"message": "Unrecognized request argument: reasoning_effort"}}, chat("ok")),
    ("argon", "meta-llama/llama-4", "reasoning", {"error": {"message": "This model does not support reasoning"}}, chat("ok")),
    ("anthropic", "claude-3-haiku", "thinking", {"error": {"message": "thinking: adaptive thinking is not supported on this model"}},
     {"content": [{"type": "text", "text": "ok"}]}),
    ("gemini", "gemini-2.0-flash", "generationConfig", {"error": {"message": "Thinking level is not supported for this model."}},
     {"candidates": [{"content": {"parts": [{"text": "ok"}]}}]}),
    ("ollama", "llama3", "think", {"error": "\"llama3\" does not support thinking"}, {"message": {"content": "ok"}}),
])
def test_a_model_that_refuses_the_reasoning_setting_is_asked_again_without(S, monkeypatch, provider, model, field, refusal, ok_answer):
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [(400, refusal), (200, ok_answer)]))
    res = S.ai_call({"provider": provider, "api_key": "k", "model": model, "prompt": "p", "custom_url": "https://x.io/v1"})
    assert res["ok"] and res["reply"] == "ok", res
    assert len(calls) == 2 and field in calls[0]["body"] and field not in calls[1]["body"]
    if provider == "anthropic":
        assert "output_config" not in calls[1]["body"] and calls[1]["body"]["max_tokens"] == 16000


def test_the_connection_test_uses_the_default_reasoning(S, monkeypatch):
    """The Test button checks the key and the model; it shouldn't pay for a long think."""
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [(200, chat("OK"))] * 2 + [(200, {"content": [{"type": "text", "text": "OK"}]})]))
    for prov, model in (("openai", "gpt-6-astra"), ("argon", "openrouter/auto"), ("anthropic", "claude-fable-5-2")):
        S.ai_call({"provider": prov, "api_key": "k", "model": model, "prompt": "Ping", "is_test": True})
    for c in calls:
        assert not {"reasoning_effort", "reasoning", "thinking", "output_config"} & set(c["body"]), c["body"]


def test_a_tiny_function_is_asked_quickly(S, monkeypatch):
    """A function of a few bytes gets low reasoning (the page sends quick): minutes of thinking on a two-byte
    function cost time and money for nothing. Everything else still gets high."""
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [(200, chat("```cpp\nvoid f() {}\n```"))] * 2))
    S.ai_call({"provider": "openai", "api_key": "k", "model": "gpt-6-astra", "prompt": "a tiny one", "quick": True})
    S.ai_call({"provider": "openai", "api_key": "k", "model": "gpt-6-astra", "prompt": "a big one"})
    assert [c["body"]["reasoning_effort"] for c in calls] == ["low", "high"]
