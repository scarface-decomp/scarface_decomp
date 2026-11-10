# What differs between the versions

Every file of each version of *Scarface: The World Is Yours* (Xbox, PC 1.00.2, PS2 and the April 2006
prototype), compared with the others: which files only one version has, which ones another version has in
another form (another sound codec, other textures, other code), and which are exactly the same. Only names,
sizes and descriptions such as "Ogg Vorbis, 48,000 Hz, stereo" are listed: nothing from the files
themselves. The website's [versions page](https://scarface-decomp.pages.dev/versions.html) shows the lists,
searchable.

The comparison hasn't been made yet. This file is replaced by it.

## Making this page

With your own copies of the versions in `binaries/` ([GAME_VERSIONS.md](GAME_VERSIONS.md)):

```
python portal/tools/version_report.py --scan
```

It reads every version (this takes a while), keeps the lists in `binaries/game_files/catalogs/` (never
committed), and writes this file and `docs/versions.json`. If you already copied the game files with the
portal's Game files section, `python portal/tools/version_report.py` uses that copy's list instead.
