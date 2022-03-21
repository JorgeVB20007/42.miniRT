# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## 2022-03-18 - Jorge
### Added
- We can now get the spot where a ray collides with a sphere and with a plane, along with the normal vector at that point.
- New utils to make a dot product of two angles and the unit vector of a vector.
### Changed
- Spheres should not show on camera when found behind it. The system to check for spheres has been changed but **(BUG)** doesn't work yet.

## 2022-03-20 - Edu
### Added
- minilibx (2020-02-19 version) added

## 2022-03-18 - Jorge
### Added
- We can now identify collisons with spheres for each vector of the cam.
- Some new functions to work with vectors (*vctr_\*_operations.c*) and colors (*rgb2int.c*).

## 2022-03-16 - Jorge
### Added
- *Coloring* section, where we'll calculate the color of each pixel for the MiniLibX to work.
- Created *line_collision_checker.c*, where we'll check if a ray collides with a certain item. It does nothing yet.
### Changed
- Most of *main()* commands are now moved to *doingcalculation()* to make space for MiniLibX.

## 2022-03-15 - Edu
### Added
- Functions to print list_rt **lst_rt_print** and filter by type **get_items_by_type**
### Changed
- Some documentation on utils
### Fixed
- Some leaks at parsing list

## 2022-03-15 - Jorge
### Added
- Every ray's vector of the camera is now calculated and returned to the **main** function

## 2022-03-13 - Edu
### Added
- Add CHANGELOG.md, README.md, Makefile
### Changed
- Structure files in folders.

