#include <TFile.h>
#include <TDirectory.h>
#include <TTree.h>
#include <TObjArray.h>
#include <TBranch.h>
/*
int convert() {
    // Open the input file
    TFile* inputFile = TFile::Open("AnalysisResults_All.root");
    if (!inputFile) {
        std::cerr << "Error: failed to open input file" << std::endl;
        return 1;
    }

    // Retrieve the tree from the input file
    TTree* inputTree;
    TDirectory* inputDirectory = (TDirectory*)inputFile->Get("PWGHF_D2H_NonPromptLctopKpiLoose_0_100");
    if (!inputDirectory) {
        std::cerr << "Error: failed to access input directory" << std::endl;
        inputFile->Close();
        return 1;
    }
    inputDirectory->GetObject("treeMLLc", inputTree);
    if (!inputTree) {
        std::cerr << "Error: failed to access input tree" << std::endl;
        inputFile->Close();
        return 1;
    }

    // Create the output file and directory
    TFile* outputFile = TFile::Open("newAnalysisResults.root", "RECREATE");
    outputFile->mkdir("newDirectory");
    outputFile->cd("newDirectory");

    // Copy the tree to the output file and directory
    TTree* outputTree = inputTree->CloneTree();
    outputTree->Write();

    // Close the input and output files
    inputFile->Close();
    outputFile->Close();

    return 0;
}
*/

/*

int convert() {
    TFile *file = TFile::Open("AnalysisResults_All.root");
    TDirectory *myDir = (TDirectory *)file->Get("PWGHF_D2H_NonPromptLctopKpiLoose_0_100");
    TFile *newFile = TFile::Open("newAnalysisResults.root", "RECREATE");




    TTree *myTree = (TTree *)myDir->Get("treeMLLc");
    TTree *clonedTree = myTree->CloneTree();

TObjArray *branches = myTree->GetListOfBranches();

for (int i = 13; i < branches->GetEntries(); i++) {
    
   TBranch *branch = (TBranch *)branches->At(i);
    std::cout << branch->GetName() << std::endl;
clonedTree->SetBranchStatus(branch->GetName(), 0);
    clonedTree->GetListOfBranches()->Remove(branch);
 }
    clonedTree->Write();
    newFile->Close();
    file->Close();

    return 0;
}
*/

int convert() {
    TFile *file = TFile::Open("AnalysisResults_MC_4.root");
    TDirectory *myDir = (TDirectory *)file->Get("PWGHF_D2H_NonPromptLctopKpiLoose_MC");
    TFile *newFile = TFile::Open("newAnalysisResults_MC_4.root", "RECREATE");

    TTree *myTree = (TTree *)myDir->Get("treeMLLc");
    TTree *newTree = new TTree("treeMLLc_new", "New tree with selected branches");

TObjArray *branches = myTree->GetListOfBranches();
for (int i = 0; i < branches->GetEntries(); i++) {
    
   TBranch *branch = (TBranch *)branches->At(i);
    std::cout << branch->GetName() << std::endl;

   
 }

 
 
    Float_t var1, var2, var3; // Define the variables you want to keep
    
    
    
/*
	myTree->SetBranchAddress("nsigTPC_Pi_0", &var1);
	myTree->SetBranchAddress("nsigTPC_K_0", &var2);
	myTree->SetBranchAddress("nsigTOF_Pi_0", &var3);

	newTree->Branch("nsigTPC_Pi_0", &var1, "nsigTPC_Pi_0/F");
	newTree->Branch("nsigTPC_K_0", &var2, "nsigTPC_K_0/F");
	newTree->Branch("nsigTOF_Pi_0", &var3, "nsigTOF_Pi_0/F");
	
	*/
	
	Float_t inv_mass, pt_cand, d_len, d_len_xy, norm_dl_xy, cos_p, cos_p_xy, imp_par_xy, dca, pt_prong0, pt_prong1, pt_prong2, sig_vert, max_norm_d0d0exp, imp_par_prong0, imp_par_prong1, imp_par_prong2;

    myTree->SetBranchAddress("inv_mass", &inv_mass);
    myTree->SetBranchAddress("pt_cand", &pt_cand);
    myTree->SetBranchAddress("d_len", &d_len);
    myTree->SetBranchAddress("d_len_xy", &d_len_xy);
    myTree->SetBranchAddress("norm_dl_xy", &norm_dl_xy);
    myTree->SetBranchAddress("cos_p", &cos_p);
    myTree->SetBranchAddress("cos_p_xy", &cos_p_xy);
    myTree->SetBranchAddress("imp_par_xy", &imp_par_xy);
    myTree->SetBranchAddress("dca", &dca);
    myTree->SetBranchAddress("pt_prong0", &pt_prong0);
    myTree->SetBranchAddress("pt_prong1", &pt_prong1);
    myTree->SetBranchAddress("pt_prong2", &pt_prong2);
    myTree->SetBranchAddress("sig_vert", &sig_vert);
    myTree->SetBranchAddress("max_norm_d0d0exp", &max_norm_d0d0exp);
    myTree->SetBranchAddress("imp_par_prong0", &imp_par_prong0);
    myTree->SetBranchAddress("imp_par_prong1", &imp_par_prong1);
    myTree->SetBranchAddress("imp_par_prong2", &imp_par_prong2);

    newTree->Branch("inv_mass", &inv_mass, "inv_mass/F");
    newTree->Branch("pt_cand", &pt_cand, "pt_cand/F");
    newTree->Branch("d_len", &d_len, "d_len/F");
    newTree->Branch("d_len_xy", &d_len_xy, "d_len_xy/F");
    newTree->Branch("norm_dl_xy", &norm_dl_xy, "norm_dl_xy/F");
    newTree->Branch("cos_p", &cos_p, "cos_p/F");
    newTree->Branch("cos_p_xy", &cos_p_xy, "cos_p_xy/F");
    newTree->Branch("imp_par_xy", &imp_par_xy, "imp_par_xy/F");
    newTree->Branch("dca", &dca, "dca/F");
    newTree->Branch("pt_prong0", &pt_prong0, "pt_prong0/F");
    newTree->Branch("pt_prong1", &pt_prong1, "pt_prong1/F");
    newTree->Branch("pt_prong2", &pt_prong2, "pt_prong2/F");
     newTree->Branch("sig_vert", &sig_vert, "sig_vert/F");
newTree->Branch("max_norm_d0d0exp", &max_norm_d0d0exp, "max_norm_d0d0exp/F");
    newTree->Branch("imp_par_prong0", &imp_par_prong0, "imp_par_prong0/F");
    newTree->Branch("imp_par_prong1", &imp_par_prong1, "imp_par_prong1/F");
    newTree->Branch("imp_par_prong2", &imp_par_prong2, "imp_par_prong2/F");
	Long64_t nEntries = myTree->GetEntries();
	for (Long64_t iEntry = 0; iEntry < nEntries; iEntry++) {
  	  var1 = 0; var2 = 0; var3 = 0; // set branch addresses to nullptr
 	   myTree->GetEntry(iEntry);
	    newTree->Fill();
}

    newFile->Write();
    newFile->Close();
    file->Close();

    return 0;
}


void merge() {
    TFile *mergedFile = TFile::Open("mergedAnalysisResults_MC.root", "RECREATE");
    TChain *mergedTree = new TChain("treeMLLc_new");

    // Add the output files from the previous conversion code to the chain
    mergedTree->Add("newAnalysisResults_MC_1.root");
    mergedTree->Add("newAnalysisResults_MC_2.root");
    mergedTree->Add("newAnalysisResults_MC_3.root");
    mergedTree->Add("newAnalysisResults_MC_4.root");

    // Copy the tree to the merged output file
    TTree *newTree = mergedTree->CloneTree();
    newTree->Write();

    mergedFile->Close();
}


