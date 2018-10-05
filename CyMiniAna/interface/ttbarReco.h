#ifndef TTBARRECO_H
#define TTBARRECO_H

#include <string>
#include <map>
#include <vector>

#include "Analysis/CyMiniAna/interface/physicsObjects.h"
#include "Analysis/CyMiniAna/interface/tools.h"
#include "Analysis/CyMiniAna/interface/configuration.h"
#include "Analysis/CyMiniAna/interface/dileptonTtbarReco.h"

class ttbarReco {
  public:
    ttbarReco( configuration& cmaConfig );

    ~ttbarReco();

    Ttbar0L ttbar0L() {return m_ttbar0L;}
    Ttbar1L ttbar1L() {return m_ttbar1L;}
    Ttbar2L ttbar2L() {return m_ttbar2L;}

    // all-hadronic
    void execute(std::vector<Ljet>& ljets);

    // single lepton
    void execute(std::vector<Lepton>& leptons, std::vector<Neutrino>& nu, std::vector<Jet>& jets, std::vector<Ljet>& ljets);

    // dilepton
    void execute(std::vector<Electron>& electrons, std::vector<Muon>& muons, std::vector<Jet>& jets);

  protected:

    configuration *m_config;

    Ttbar0L m_ttbar0L;
    Ttbar1L m_ttbar1L;
    Ttbar2L m_ttbar2L;

    dileptonTtbarReco* m_dileptonTtbar;
    DileptonReco m_dilepton;

    std::map<std::string,int> m_mapContainment;
    std::map<std::string,int> m_targetMap;

    // Leopard info
    TFile* m_lh_file;
    TH1D* m_mlb_bckg;
    TH1D* m_mlb_sig;
    TH1D* m_csv_bckg;
    TH1D* m_csv_sig;
    TAxis* m_xmlb;
    TAxis* m_xcsv;

    float M_HALF_PI = M_PI*0.5;
};

#endif
