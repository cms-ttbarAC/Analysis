10 March 2018  
Dan Marley  


# CyMiniAna

#### C++/Python Analysis Framework

This class is derived from the [CyMiniAna](https://gitlab.cern.ch/dmarley/CyMiniAna) base class.  
Dependencies (available in CMSSW):

    - ROOT6
    - python2.7 (matplotlib & numpy)


## Overview

CyMiniAna is built for the ttbar charge asymmetry analyses to do the following:


1. Make smaller root files based on a selection criteria ("skimming" or "slimming")
    a. These root files can be used for any tasks mentioned below, and preparing inputs for unfolding/combinations.
2. Make histograms from existing root files (with or without applying an event selection)
    a. These histograms can be used as inputs for unfolding
3. Make efficiency curves from existing root files (with or without applying an event selection)

The CyMiniAna Analysis Framework is structured as follows:

Directory  | About
---------  | ---------
bin/       | steering macros
config/    | text files and generic information
examples/  | Example scripts demonstrating how to use framework or general coding
interface/ | `*.h` files
python/    | plotting, neural network, batch, and running scripts
src/       | `*.cxx` files
BuildFile.xml | File used by `scram` to compile software in CMSSW
Makefile   | compiles c++ code -- not needed in CMSSW framework!
README.md  | This file
setup.sh   | Setup script for cmssw environment



## Getting Started

Before running an analysis, make a new branch to perform your work.  
It is recommend that you make a new branch from a specific tag.

**DO NOT USE THE MASTER BRANCH FOR DEVELOPMENT OR RUNNING AN ANALYSIS**  
_The master branch is only used to make new tags!_

Anytime you modify `*.cxx` or `*.h` code, be sure to recompile:
```shell
scram b -j8
```

# More Information

Please consult the [wiki](https://github.com/cms-ttbarAC/CyMiniAna/wiki) pages for more information.

# Contact

If there are questions, concerns, or bugs found, please create an issue or PR.  
If you would like contribute to the project, it is recommended to follow the 
[feature branch workflow](https://www.atlassian.com/git/tutorials/comparing-workflows/feature-branch-workflow).  
See `CONTRIBUTING.md` for more information.
