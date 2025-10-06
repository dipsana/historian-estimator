# Changelog

All notable changes to Historian's Estimator will be documented in this file.

## \[v1.0.0] - 2024-10-06

### Added

- Initial release of Historian's Estimator
- Date difference calculation between two Gregorian dates
- Smart auto-correction for invalid/overflow date values
- Support for historical dates (±32,767 years)
- Interactive session mode with continuous operation
- Dual output format (days and years/months/days)
- Input validation and error handling
- AD notation support for historical dates
- Added project structure and documentation files:

  - `/bin/historian_estimator.exe`
  - `/src/main.c`
  - `/docs/srs.pdf`
  - `CHANGELOG.md`
  - `LICENSE`
  - `README.md`

### Technical

- Single-file C implementation (~7 KB source)
- Cross-platform compatibility
- Standard C library only (no external dependencies)

---

**Versioning:** This project adheres to [Semantic Versioning 2.0.0](https://semver.org/).  
**Changelog Format:** Based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/).

