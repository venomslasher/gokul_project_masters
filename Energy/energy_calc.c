
//Function to calculate the energy of the neutrino 
double E(double pux,double puy, double puz,double theta)
{
	
	double mn= 939.56542052;//mass of neutron
	double mp= 938.27208816 ;//mass of proton
	double mu=105.6583755;//mass of muon
	theta = theta*22.0/(7.0*180.0);
	double cost = TMath::Cos(theta);
	double Eb = 34.0; // binding energy of proton-carbon nucleus
	double nume, deno, mp2,mn2,mu2;
	mp2 = TMath::Power(mp,2.0);
	mn2 = TMath::Power(mn,2.0);
	mu2 = TMath::Power(mu,2.0);
	double Eu = TMath::Power(pux*pux  +puy*puy+puz*puz + mu2, 0.5);
	nume = mp2 - TMath::Power(mn-Eb, 2.0) -mu2 + 2.0* (mn-Eb)*Eu;
	deno = 2.0*( mn-Eb-Eu + puz*cost);
	return (nume/deno);

}

//Function to calculate the q-square value 
double Q2(double pux,double puy, double puz, double theta)
{
	
	double mn= 939.56542052;//mass of neutron
	double mp= 938.27208816 ;//mass of proton
	double mu=105.6583755;//mass of muon
	theta = theta*22.0/(7.0*180.0);
	double cost = TMath::Cos(theta);
	double Eb = 34.0; // binding energy of proton-carbon nucleus
	double nume, deno, mp2,mn2,mu2;
	mp2 = TMath::Power(mp,2.0);
	mn2 = TMath::Power(mn,2.0);
	mu2 = TMath::Power(mu,2.0);
	double Eu = TMath::Power(pux*pux  +puy*puy+puz*puz + mu2, 0.5);
	nume = mp2 - TMath::Power(mn-Eb, 2.0) -mu2 + 2.0* (mn-Eb)*Eu;
	deno = 2.0*( mn-Eb-Eu + puz*cost);
	double q2 = (nume/deno)*2*(puz)-mu2;
	return q2;

}


//function that handles the reading of data entries and calculate the energy of reacting neutrino
void energy_calc(){

	TFile *f = new TFile("ABC.root","read");  //reading the root file named 'ABC.root'
	TFile *outfile = new TFile("EQm.root", "recreate"); //creating the root file named 'EQm.root' to store the calculated values
	
	TTree* tree = (TTree*) f->Get("ABCTree");
	TTree* tree2 = new TTree("mutree", "mutree");//tree that will store the values
	
	int entries = tree ->GetEntries();
	
	int bin_r = ceil(2*(TMath::Power((double)entries, .33)));
	TRandom3 *rand = new TRandom3();
	double mpx,mpy,mpz,Eqccg,q2ccg,r;
	
	tree ->SetBranchAddress("Muonpx",&mpx);
	tree ->SetBranchAddress("Muonpy",&mpy);
	tree ->SetBranchAddress("Muonpz",&mpz);
	tree2 -> Branch("Eqccg", &Eqccg, "Eqccg/D");
	tree2 -> Branch("q2ccg", &q2ccg, "q2ccg/D");
	
	//for loop to iterate through all entries of the tree
	for(int i =0; i<entries;i++)
	{	
		tree->GetEntry(i);
		r = rand ->Gaus(0,.25);
		r = r*40;
		Eqccg = E(mpx,mpy,mpz,r);
		q2ccg = Q2(mpx,mpy,mpz,r);
		tree2 ->Fill();
	}
	
	outfile ->Write();	
	outfile -> Close();
	f ->Close();

}


