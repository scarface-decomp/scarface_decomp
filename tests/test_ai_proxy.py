"""The AI proxy (decomp_portal_server.ai_call) without network: request shapes, retries and key hygiene."""
import json

import pytest

import conftest  # noqa: F401  (puts tools/ on the path)


@pytest.fixture()
def S(monkeypatch):
    import importlib, sys
    sys.path.insert(0, str(conftest.ROOT))
    mod = importlib.import_module("decomp_portal_server")
    return mod


def fake_http(calls, answers):
    def _http_json(url, body, headers, timeout=180):
        calls.append({"url": url, "body": json.loads(json.dumps(body)) if body is not None else None, "headers": headers})
        st, j = answers.pop(0)
        return st, j, json.dumps(j)
    return _http_json


def test_openai_retries_without_temperature(S, monkeypatch):
    calls = []
    answers = [(400, {"error": {"message": "Unsupported value: 'temperature' does not support 0.2 with this model."}}),
               (200, {"model": "gpt-5.6-terra", "choices": [{"message": {"content": "int f() { return 1; }"}}]})]
    monkeypatch.setattr(S, "_http_json", fake_http(calls, answers))
    res = S.ai_call({"provider": "openai", "api_key": "sk-test", "model": "gpt-5.6-terra", "prompt": "p"})
    assert res == {"ok": True, "reply": "int f() { return 1; }", "used_model": "gpt-5.6-terra"}
    assert calls[0]["body"]["temperature"] == 0.2 and "temperature" not in calls[1]["body"]
    assert calls[0]["headers"]["Authorization"] == "Bearer sk-test"


def test_anthropic_and_gemini_retry_too(S, monkeypatch):
    calls = []
    answers = [(400, {"error": {"message": "temperature is not supported"}}),
               (200, {"model": "claude-sonnet-5-5", "content": [{"type": "text", "text": "ok"}]})]
    monkeypatch.setattr(S, "_http_json", fake_http(calls, answers))
    res = S.ai_call({"provider": "anthropic", "api_key": "k", "model": "claude-sonnet-5-5", "prompt": "p"})
    assert res["ok"] and res["reply"] == "ok" and "temperature" not in calls[1]["body"]
    assert calls[0]["headers"]["x-api-key"] == "k" and calls[0]["headers"]["anthropic-version"]

    calls.clear()
    answers[:] = [(400, {"error": {"message": "temperature is deprecated"}}),
                  (200, {"candidates": [{"content": {"parts": [{"text": "hi"}]}}]})]
    res = S.ai_call({"provider": "gemini", "api_key": "g", "model": "gemini-3.8-flash", "prompt": "p"})
    assert res == {"ok": True, "reply": "hi", "used_model": "gemini-3.8-flash"}
    assert "generationConfig" not in calls[1]["body"] and calls[0]["url"].endswith("gemini-3.8-flash:generateContent")


def test_errors_never_include_the_key(S, monkeypatch):
    calls = []
    monkeypatch.setattr(S, "_http_json", fake_http(calls, [(401, {"error": "bad key sk-secret-999"})]))
    res = S.ai_call({"provider": "openai", "api_key": "sk-secret-999", "model": "gpt-5.6-luna", "prompt": "p"})
    assert not res["ok"] and "sk-secret-999" not in res["error"] and "***" in res["error"]


def test_input_checks(S):
    assert "API key" in S.ai_call({"provider": "gemini", "prompt": "p"})["error"]
    assert "Unknown provider" in S.ai_call({"provider": "x", "api_key": "k", "prompt": "p"})["error"]
    assert "Empty prompt" in S.ai_call({"provider": "openai", "api_key": "k"})["error"]
    assert "http" in S.ai_call({"provider": "custom_api", "api_key": "k", "prompt": "p", "custom_url": "file:///x"})["error"]
