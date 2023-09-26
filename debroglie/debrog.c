//Function that will calculate and plot debrogle wavelength
void debrog(){

	TFile *f = new TFile("ABC.root","read");
	TTree* tree = (TTree*) f->Get("ABCTree");
	
	int entries = tree ->GetEntries();	
	double npx,npy,npz,p;
	
	tree ->SetBranchAddress("Netpx",&npx);
	tree ->SetBranchAddress("Netpy",&npy);
	tree ->SetBranchAddress("Netpz",&npz);
		
	int bin_x = 100;
	
	//initialising 1D hitogram
	TH1D* hist = new TH1D("#lambda", "#lambda", bin_x,  0,1);
	
	for(int i =0; i<entries;i++){
	
		tree->GetEntry(i);
		p = TMath::Power(npx*npx+npy*npy+npz*npz, 0.5);
		p= 1240.7/p;
		hist-> Fill(p);
	
	}

	gStyle -> SetOptFit(1111);
	
	hist ->GetXaxis()->SetTitle("#lambda fm");	
	hist ->GetYaxis()->SetTitle("count");
	
	TCanvas* c1 = new TCanvas("Px");
	hist -> Draw("HIST SAME e FUNC");
	
	c1->SaveAs("debrog.svg");
	
}


