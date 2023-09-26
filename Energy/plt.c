#include <iostream>

//a root macro that will handle the plotting
void plt()
{

	TFile *file2 = new TFile("KE.root", "READ");
	TTree* tree2 = (TTree*) file2-> Get("KEtree");
	
	int entries2 = tree2 ->GetEntries();

	TH1D* hist2 =new TH1D("KE of #nu + #mu", "KE", 80, 0,10000);
	
	double KE;
	tree2 ->SetBranchAddress("KE", &KE);
	
	for(int i =0; i<entries2;i++)
	{	
		tree2->GetEntry(i);
		hist2 ->Fill(KE);
	}
	
	TFile *file = new TFile("EQm.root", "READ");
	TTree* tree = (TTree*) file-> Get("mutree");
	
	int entries = tree ->GetEntries();
	
	//1D histogram to plot the energy curve
	TH1D* hist =new TH1D("E^{#nu}_{cc}", "Reconstructed #nu_{#mu} energy from #mu kinematics", 80, 0,10000);
	
	double Eqcc,q2cc;
	
	tree ->SetBranchAddress("Eqccg", &Eqcc);
	tree ->SetBranchAddress("q2ccg", &q2cc);
	
	for(int i =0; i<entries;i++)
	{	
		tree->GetEntry(i);
		hist ->Fill(Eqcc);
	}
	
	TCanvas* c1 = new TCanvas("E1");
	gStyle->SetOptFit(111);
	//hist -> Draw("HIST SAME E FUNC");
	hist->Scale(1. / hist->Integral(), "width");//normalising the curve with area
	hist ->GetXaxis()->SetTitle("E^{#nu}_{cc}, MeV");
    hist ->GetYaxis()->SetTitle("Relative frequency");
	//hist ->Fit("gaus");
	hist ->Draw();
	hist2 ->Draw();


}
