
void plotp(){

	TFile *f = new TFile("ABC.root","read");
	TTree* tree = (TTree*) f->Get("ABCTree");
	
	int entries = tree ->GetEntries();
	
	
	double npx,npy,npz,ppx,ppy,ppz,mpx,mpy,mpz;
	
	//n stands for neutrino, p for proton, m for muon
	//px is x component of momentum. py is y component of momentum and pz is z component of momentum

	//setting for neutrino
	tree ->SetBranchAddress("Netpx",&npx);
	tree ->SetBranchAddress("Netpy",&npy);
	tree ->SetBranchAddress("Netpz",&npz);
	//setting for muon
	tree ->SetBranchAddress("Muonpx",&mpx);
	tree ->SetBranchAddress("Muonpy",&mpy);
	tree ->SetBranchAddress("Muonpz",&mpz);
	//setting for proton
	tree ->SetBranchAddress("Protonpx",&ppx);
	tree ->SetBranchAddress("Protonpy",&ppy);
	tree ->SetBranchAddress("Protonpz",&ppz);
	
	//bin sizes for momentum plots of proton 
	int bin_px =60;
	int bin_py = 50;
	int bin_pz = 70;
	
	//bin sizes for momentum plots of neutrino 
	int bin_nx = 100;
	int bin_ny = 80;
	int bin_nz = 65;
	
	//bin sizes for momentum plots of muon 
	int bin_mx = 100;
	int bin_my = 70;
	int bin_mz = 70;
	
	
	
	//initialising histogram to plot components of proton momentum
	TH1D* histpx = new TH1D("Proton px", "Normalised Px of Proton", bin_px,  -1000.16,1000.52);
	TH1D* histpy = new TH1D("Proton py", "Normalised Py of Proton", bin_py, -1000.27,1000.7);
	TH1D* histpz = new TH1D("Proton pz", "Normalised Pz of Proton", bin_pz,  -100,2000.88);
	

	//initialising histogram to plot components of muon momentum
	TH1D* histmx = new TH1D("muon px", "Normalised Px of Muon", bin_mx,  -1000.16,1000.52);
	TH1D* histmy = new TH1D("muon py", "Normalised Py of Muon", bin_my, -1000.27,1000.7);
	TH1D* histmz = new TH1D("muon pz", "Normalised Pz of Muon", bin_mz,  451.81,10000.88);
	
	//initialising histogram to plot components of neutrino momentum
	TH1D* histnx = new TH1D("#nu_{#mu} px", "Normalised Px of neutrino", bin_nx,  -1000.16,1000.52);
	TH1D* histny = new TH1D("#nu_{#mu} py", "Normalised Py of neutrino", bin_ny, -1000.27,1000.7);
	TH1D* histnz = new TH1D("#nu_{#mu} pz", "Normalised Pz of neutrino", bin_nz,  451.81,10000.88);
	

	//loop to read values from tree and to fill all of the hisogram
	for(int i =0; i<entries;i++){
	
		tree->GetEntry(i);
		histpx-> Fill(ppx);
		histpy-> Fill(ppy);
		histpz-> Fill(ppz);
		
		histmx-> Fill(mpx);
		histmy-> Fill(mpy);
		histmz-> Fill(mpz);
		
		histnx-> Fill(npx);
		histny-> Fill(npy);
		histnz-> Fill(npz);
	
	}

	
	gStyle -> SetOptFit(1111);
	
	//plot labeling for proton momentum components starts here.
	histpx ->GetXaxis()->SetTitle("px MeV/c");
	histpy ->GetXaxis()->SetTitle("py MeV/c");
	histpz ->GetXaxis()->SetTitle("pz MeV/c");
	
	histpx ->GetYaxis()->SetTitle("Relative frequency");
	histpy ->GetYaxis()->SetTitle("Relative frequency");
	histpz ->GetYaxis()->SetTitle("Relative frequency");
	
	//area normalising
	histpx->Scale(1. / histpx->Integral(), "width");
	histpy->Scale(1. / histpy->Integral(), "width");
	histpz->Scale(1. / histpz->Integral(), "width");
	//plot labeling for proton momentum components ends here.

	//plot labeling for neutrino momentum components starts here.
	histnx ->GetXaxis()->SetTitle("px MeV/c");
	histny ->GetXaxis()->SetTitle("py MeV/c");
	histnz ->GetXaxis()->SetTitle("pz MeV/c");
	
	histnx ->GetYaxis()->SetTitle("Relative frequency");
	histny ->GetYaxis()->SetTitle("Relative frequency");
	histnz ->GetYaxis()->SetTitle("Relative frequency");


	//area normalising
	histnx->Scale(1. / histnx->Integral(), "width");
	histny->Scale(1. / histny->Integral(), "width");
	histnz->Scale(1. / histnz->Integral(), "width");
	//plot labeling for neutrino momentum components ends here.

	//plot labeling for muon momentum components starts here.
	histmx ->GetXaxis()->SetTitle("px MeV/c");
	histmy ->GetXaxis()->SetTitle("py MeV/c");
	histmz ->GetXaxis()->SetTitle("pz MeV/c");
	
	histmx ->GetYaxis()->SetTitle("Relative frequency");
	histmy ->GetYaxis()->SetTitle("Relative frequency");
	histmz ->GetYaxis()->SetTitle("Relative frequency");


	//area normalising
	histmx->Scale(1. / histmx->Integral(), "width");
	histmy->Scale(1. / histmy->Integral(), "width");
	histmz->Scale(1. / histmz->Integral(), "width");
	//plot labeling for muon momentum components ends here
	
	TCanvas* cpx = new TCanvas("Px");
	//histpx ->Fit("gaus");
	histpx -> Draw("HIST SAME e FUNC");
	
	TCanvas* cpy = new TCanvas("Py");
	//histpy->Fit("gaus");
	histpy -> Draw("HIST SAME e FUNC");
	
	TCanvas* cpz = new TCanvas("Pz");
	//histpz->Fit("gaus");
	histpz -> Draw("HIST SAME e FUNC");
	
	
	TCanvas* cnx = new TCanvas("Px");
	//histnx ->Fit("gaus");
	histnx -> Draw("HIST SAME e FUNC");
	
	TCanvas* cny = new TCanvas("Py");
	//histny->Fit("gaus");
	histny -> Draw("HIST SAME e FUNC");
	
	TCanvas* cnz = new TCanvas("Pz");
	//histnz->Fit("gaus");
	histnz -> Draw("HIST SAME e FUNC");
	
	
	TCanvas* cmx = new TCanvas("Px");
	//histmx ->Fit("gaus");
	histmx -> Draw("HIST SAME e FUNC");
	
	TCanvas* cmy = new TCanvas("Py");
	//histmy->Fit("gaus");
	histmy -> Draw("HIST SAME e FUNC");
	
	TCanvas* cmz = new TCanvas("Pz");
	//histmz->Fit("gaus");
	histmz -> Draw("HIST SAME e FUNC");
	

	//following lines will save all the plots to svg files
	cpx->SaveAs("ppx.svg");
	cpy->SaveAs("ppy.svg");
	cpz->SaveAs("ppz.svg");
	
	cnx->SaveAs("npx.svg");
	cny->SaveAs("npy.svg");
	cnz->SaveAs("npz.svg");
	
	cmx->SaveAs("mpx.svg");
	cmy->SaveAs("mpy.svg");
	cmz->SaveAs("mpz.svg");
}


