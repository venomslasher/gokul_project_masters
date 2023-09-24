
void plotp(){

	TFile *f = new TFile("ABC.root","read");
	TTree* tree = (TTree*) f->Get("ABCTree");
	
	int entries = tree ->GetEntries();
	
	
	double npx,npy,npz,ppx,ppy,ppz,mpx,mpy,mpz;
	
	tree ->SetBranchAddress("Protonpx",&npx);
	tree ->SetBranchAddress("Protonpy",&npy);
	tree ->SetBranchAddress("Protonpz",&npz);
	
	tree ->SetBranchAddress("Muonpx",&mpx);
	tree ->SetBranchAddress("Muonpy",&mpy);
	tree ->SetBranchAddress("Muonpz",&mpz);
	
	tree ->SetBranchAddress("Protonpx",&ppx);
	tree ->SetBranchAddress("Protonpy",&ppy);
	tree ->SetBranchAddress("Protonpz",&ppz);
		
	int bin_px =60;
	int bin_py = 50;
	int bin_pz = 70;
	
	int bin_nx = 100;
	int bin_ny = 80;
	int bin_nz = 65;
	
	int bin_mx = 100;
	int bin_my = 70;
	int bin_mz = 70;
	
	
	
	
	TH1D* histpx = new TH1D("Proton px", "Normalised Px of Proton", bin_px,  -1000.16,1000.52);
	TH1D* histpy = new TH1D("Proton py", "Normalised Py of Proton", bin_py, -1000.27,1000.7);
	TH1D* histpz = new TH1D("Proton pz", "Normalised Pz of Proton", bin_pz,  -100,2000.88);
	
	TH1D* histmx = new TH1D("muon px", "Normalised Px of Muon", bin_mx,  -1000.16,1000.52);
	TH1D* histmy = new TH1D("muon py", "Normalised Py of Muon", bin_my, -1000.27,1000.7);
	TH1D* histmz = new TH1D("muon pz", "Normalised Pz of Muon", bin_mz,  451.81,10000.88);
	
	
	TH1D* histnx = new TH1D("#nu_{#mu} px", "Normalised Px of neutrino", bin_nx,  -1000.16,1000.52);
	TH1D* histny = new TH1D("#nu_{#mu} py", "Normalised Py of neutrino", bin_ny, -1000.27,1000.7);
	TH1D* histnz = new TH1D("#nu_{#mu} pz", "Normalised Pz of neutrino", bin_nz,  451.81,10000.88);
	
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
	
	histpx ->GetXaxis()->SetTitle("px MeV/c");
	histpy ->GetXaxis()->SetTitle("py MeV/c");
	histpz ->GetXaxis()->SetTitle("pz MeV/c");
	
	histpx ->GetYaxis()->SetTitle("Relative frequency");
	histpy ->GetYaxis()->SetTitle("Relative frequency");
	histpz ->GetYaxis()->SetTitle("Relative frequency");
	
	histpx->Scale(1. / histx->Integral(), "width");
	histpy->Scale(1. / histy->Integral(), "width");
	histpz->Scale(1. / histz->Integral(), "width");
	
	histnx ->GetXaxis()->SetTitle("px MeV/c");
	histny ->GetXaxis()->SetTitle("py MeV/c");
	histnz ->GetXaxis()->SetTitle("pz MeV/c");
	
	histnx ->GetYaxis()->SetTitle("Relative frequency");
	histny ->GetYaxis()->SetTitle("Relative frequency");
	histnz ->GetYaxis()->SetTitle("Relative frequency");
	
	histnx->Scale(1. / histx->Integral(), "width");
	histny->Scale(1. / histy->Integral(), "width");
	histnz->Scale(1. / histz->Integral(), "width");
	
	histmx ->GetXaxis()->SetTitle("px MeV/c");
	histmy ->GetXaxis()->SetTitle("py MeV/c");
	histmz ->GetXaxis()->SetTitle("pz MeV/c");
	
	histmx ->GetYaxis()->SetTitle("Relative frequency");
	histmy ->GetYaxis()->SetTitle("Relative frequency");
	histmz ->GetYaxis()->SetTitle("Relative frequency");
	
	histmx->Scale(1. / histx->Integral(), "width");
	histmy->Scale(1. / histy->Integral(), "width");
	histmz->Scale(1. / histz->Integral(), "width");
	
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

