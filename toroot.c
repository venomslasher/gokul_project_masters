

int toroot()
{
	auto fileName = "ABC.csv";
	auto rdf = ROOT::RDF::MakeCsvDataFrame(fileName);
	rdf.Snapshot("ABCTree", "ABC.root");
	return 0;
}
