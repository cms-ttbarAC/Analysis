# Analysis
Analysis framework for cms top quark charge asymmetry

This repository contains software for performing the charge asymmetry analysis in CMS.
There are two main directories:

- Genesis
    - Originally developed [here](https://github.com/cms-ttbarAC/ttbarAC_skim) as `ttbarAC_skim`.
    - This framework generates flat ntuples from MiniAOD.
- CyMiniAna
    - Originally developed [here](https://github.com/cms-ttbarAC/CyMiniAna).
    - This is the local analysis framework that processes 
      flat ntuples and produces TTrees/histograms/efficiencies/etc.

Additionally, a [submodule](https://git-scm.com/book/en/v2/Git-Tools-Submodules) 
for [hepPlotter](https://github.com/demarley/hepPlotter) 
is also included in this project.

## Getting Started

Create a CMSSW environment:
```
cmsrel CMSSW_9_4_4
cd CMSSW_9_4_4/src
cmsenv
```

Check out necessary packages (including this one):
```
### 2016 ###
# VID (Electron ID)
git cms-addpkg RecoEgamma/ElectronIdentification
git cms-addpkg PhysicsTools/SelectorUtils

### 2017 ###
# Updated Egamma IDs (creates RecoEgamma and PhysicsTools directories)
# https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedElectronIdentificationRun2
git cms-merge-topic lsoffi:CMSSW_9_4_0_pre3_TnP

# BEST (top vs qcd tagging)
git clone https://github.com/cms-ttbarAC/BESTAnalysis.git -b 94X
# LWTNN (running BEST in c++)
mkdir lwtnn
git clone https://github.com/demarley/lwtnn.git -b CMSSW_8_0_X-compatible lwtnn/lwtnn

## This framework 
#  without the submodule:
git clone https://github.com/cms-ttbarAC/Analysis.git   # you need to manually fetch hepPlotter

# with the submodule:
git clone --recurse-submodules https://github.com/cms-ttbarAC/Analysis.git
```

# Questions and Comments

Please submit an issue or a PR.
