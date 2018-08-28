# Genesis

Framework for creating samples (flat ntuples) from MiniAOD for ttbar charge asymmetry analysis.  
The framework is setup for running at the LPC, and saving ntuples to the LPC Tier3.


## Getting Started

Check out CMSSW release:
```
cmsrel CMSSW_9_4_4
cd CMSSW_9_4_4/src
cmsenv
git cms-init
```

## Ntuple Production

Instructions for producing flat Ntuples with BEST tagger inputs.

```
cd Analysis/Genesis/test
voms-proxy-init -voms cms
source /cvmfs/cms.cern.ch/crab3/crab.csh
```

To submit crab jobs, the script `runSkim.py` is processed using the `cmsRun` executable.  
There are two options for submitting crab jobs:
1. Submit many jobs at once
2. Submit jobs manually one at a time

### Multiple Submission

Write a text file that contains the datasets you would like to process, see `test/crab_datasets-data.txt` and `test/crab_datasets-mc.txt` as examples (or you can use these files).  
Then, execute the script with your datsets text file as a command-line argument: 
```
python crab-submit-multiple.py <datasets.txt> <year>
```
If no command-line argument is given, a default file & year will be chosen.
This script will loop through the different datasets and submit crab jobs for each one.

#### Example Dataset File
_The text file needs to be written such that each sample has a 'nickname' that can be used to create the crab directory.  The example text files include this structure -- replicate it if you write your own file!_  
Example: filename = "example.txt"; content =
```
ttbar /TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM`
```
where `ttbar` is the nickname, and `/TT.../MINIAODSIM` is the sample.  
Then, the jobs would be submitted as:  
`python crab-submit-multiple.py example.txt 2016`

### Single Submission
_The following method is not recommended.  Instead, if you want to only submit one sample, use the method described in "Multiple Submission" and fill your text file with only 1 dataset._

Edit `crab_*.py` with a new dataset name to reflect the sample you are processing, e.g., `crab_SMttbar.py`.  
Make sure to the output directory is pointed to `/store/group/lpctop/ttbarAC/ttbarAC_skim/`.  
If you are processing data, modify the argument `config.JobType.pyCfgParams = ['isMC=True']` to `config.JobType.pyCfgParams = ['isMC=False']`.  
To submit the CRAB jobs, enter the command:
```
crab submit -c crab_*.py --dryrun
crab proceed
```
You can also submit the crab jobs directly by removing `--dryrun`.

For either option, it is necessary to monitor the CRAB jobs and resubmit any that fail.


## Questions
Post an issue or PR.
