#include "TUnfolder.h"
#include <TF1.h>
#include <TH2.h>
#include <TFile.h>
#include <TTree.h>

void TUnfolder::GenerateTestTree(const char* outputFileName)
{
  const unsigned int nEvents         = 10000;
  const        float x_true_mean     = 0.;
  const        float x_true_std      = .1;
  const        float x_measured_mean = 0.;
  const        float x_measured_std  = 1.;
  const          int nBinsX = 20;
  const        float xMin   = -1.;
  const        float xMax   = +1.;
  const          int nBinsY = 80;
  const        float yMin   = -4.;
  const        float yMax   = +4.;

  float x_true;
  float x_measured;

  const char* fileTitle = "Test Data for TUnfolder";

  TFile fOutput(outputFileName, "RECREATE", fileTitle);
  TTree tree("tTestTree", "Unfolding Test Tree");

  tree.Branch("x_true", &x_true, "x_true/F");
  tree.Branch("x_measured", &x_measured, "x_measured/F");

  TF1 fTrue("fTrue", "TMath::Gaus(x, [0], [1])", -3, 3);
  fTrue.SetParameter(0, x_true_mean);
  fTrue.SetParameter(1, x_true_std);

  TF1 fMeasured("fMeasured", "TMath::Gaus(x, [0], [1])", -3, 3);
  fMeasured.SetParameter(0, x_measured_mean);
  fMeasured.SetParameter(1, x_measured_std);

  TH2F hResponse("hResponse", "Response Matrix", nBinsX, xMin, xMax, nBinsY, yMin, yMax);
  UNFOUT << "Generating test data ... ";
  for( unsigned int e = 0; e < nEvents; e++ )
  {
    x_true     = fTrue.GetRandom();
    x_measured = fMeasured.GetRandom();

    hResponse.Fill(x_true, x_measured);
    tree.Fill();
  }
  std::cout << "DONE" << std::endl;

  hResponse.Write();
  if( fOutput.Write() ) UNFOUT << "Test data generated at " << fOutput.GetName() << std::endl;
  fOutput.Close();
}
