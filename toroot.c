

int toroot()
{
	auto fileName = "ABC.csv"; //filename of the csv file to be converted to root
	auto rdf = ROOT::RDF::MakeCsvDataFrame(fileName);
	rdf.Snapshot("ABCTree", "ABC.root"); // "ABCTree" is the name of the tree to be created containing the data and ABC.root is the root file
	return 0;
}
