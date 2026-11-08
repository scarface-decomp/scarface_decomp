# Project website

`docs/index.html` is the public project page, live at **https://scarface-decomp.pages.dev**: progress,
the verified functions with their code, and how to help. It has no build step and no dependencies.
It is hosted on the project's Cloudflare account (`scarface-decomp` Pages project), which rebuilds it
on every push to `main`.

## Where its data comes from

The page reads two files that the portal and `scripts/reverify_all.py` keep up to date:
`reports/progress.json` and `reports/verified_registry.json`. It looks for them in this order:

1. `data/` next to the page. The Cloudflare Pages build copies the two files there on every push.
2. The repository on `raw.githubusercontent.com`. That covers GitHub Pages, or a deploy without
   step 1.

So every push to `main`, including the portal's **Sync Verified to GitHub**, updates the site.

## Cloudflare Pages settings

| Setting | Value |
| :--- | :--- |
| Production branch | `main` |
| Framework preset | None |
| Build command | `mkdir -p docs/data && cp reports/progress.json reports/verified_registry.json docs/data/` |
| Build output directory | `docs` |

## Testing locally

```bash
python -m pytest -q tests/test_site_e2e.py
```

Or serve it yourself: copy the two report files into `docs/data/` (ignored by git) and run
`python -m http.server -d docs 8000`, then open http://localhost:8000.
