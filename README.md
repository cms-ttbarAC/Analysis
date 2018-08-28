# Analysis
Analysis framework for cms top quark charge asymmetry

This repository contains software for performing the charge asymmetry analysis in CMS.
There are two main directories:

- CyMiniAna
- genesis

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

git clone https://github.com/cms-ttbarAC/Analysis.git

```

# Questions and Comments

Please submit an issue or a PR.
