#include <dirent.h> // for directory handling
#include <string> // for string manipulation
#include <TFile.h>
#include <TDirectory.h>
#include <TTree.h>
#include <TObjArray.h>
#include <TBranch.h>
#include <filesystem>



int convert(std::string filename) {


    TFile *file = TFile::Open(filename.c_str());
    if (!file || file->IsZombie()) {
    std::cout << "Failed to open file: " << filename << std::endl;
    return 0;
}
    TDirectory *myDir = (TDirectory *)file->Get("PWGHF_D2H_NonPromptLctopKpiLoose_0_100");\
    
    
    if (!myDir) {
    std::cout << "Failed to find directory: PWGHF_D2H_NonPromptLctopKpiLoose_0_100 in file: " << filename << std::endl;
    return 0;
}
/*
     std::string prefix = "new_";
     std::filesystem::path filePath(file->GetName());
     std::string name = filePath.filename().string();
      std::string newFilename = prefix + name;
   //  std::string newFilename = prefix+file->GetName();
      cout<<newFilename.c_str()<<endl;
//return 0;
  
    TFile *newFile = TFile::Open(newFilename.c_str(), "RECREATE");
*/
    
    std::string prefix = "new_";
    std::filesystem::path filePath(file->GetName());
    std::string name = filePath.filename().string();
    std::string newFilename = prefix + name;

    // specify output directory
    std::string outdir = "/Users/oveis/Desktop/child1_extra/temp/";
    newFilename = outdir + newFilename; // append directory to filename

    cout << newFilename.c_str() << endl;

    TFile *newFile = TFile::Open(newFilename.c_str(), "RECREATE");

    TTree *myTree = (TTree *)myDir->Get("treeMLLc");
    TTree *newTree = new TTree("treeMLLc_new", "New tree with selected branches");

TObjArray *branches = myTree->GetListOfBranches();
for (int i = 0; i < branches->GetEntries(); i++) {
    
   TBranch *branch = (TBranch *)branches->At(i);
    std::cout << branch->GetName() << std::endl;

   
 }

 
 
    Float_t var1, var2, var3; // Define the variables you want to keep
    
    
    

  //myTree->SetBranchAddress("nsigTPC_Pi_0", &var1);
//  myTree->SetBranchAddress("nsigTPC_K_0", &var2);
  //myTree->SetBranchAddress("nsigTOF_Pi_0", &var3);

  //newTree->Branch("nsigTPC_Pi_0", &var1, "nsigTPC_Pi_0/F");
//  newTree->Branch("nsigTPC_K_0", &var2, "nsigTPC_K_0/F");
//  newTree->Branch("nsigTOF_Pi_0", &var3, "nsigTOF_Pi_0/F");
  
  Float_t inv_mass, pt_cand, d_len, d_len_xy, norm_dl_xy, cos_p, cos_p_xy, imp_par_xy, dca, nsigTPC_Pi_0, nsigTPC_Pi_1, nsigTPC_Pi_2, nsigTPC_K_0, nsigTPC_K_1, nsigTPC_K_2, nsigTPC_Pr_0, nsigTPC_Pr_1, nsigTPC_Pr_2, nsigTOF_Pi_0, nsigTOF_Pi_1, nsigTOF_Pi_2, nsigTOF_K_0, nsigTOF_K_1, nsigTOF_K_2, sig_vert, max_norm_d0d0exp, imp_par_prong0, imp_par_prong1, imp_par_prong2;

myTree->SetBranchAddress("inv_mass", &inv_mass);
myTree->SetBranchAddress("pt_cand", &pt_cand);
myTree->SetBranchAddress("d_len", &d_len);
myTree->SetBranchAddress("d_len_xy", &d_len_xy);
myTree->SetBranchAddress("norm_dl_xy", &norm_dl_xy);
myTree->SetBranchAddress("cos_p", &cos_p);
myTree->SetBranchAddress("cos_p_xy", &cos_p_xy);
myTree->SetBranchAddress("imp_par_xy", &imp_par_xy);
myTree->SetBranchAddress("dca", &dca);
myTree->SetBranchAddress("nsigTPC_Pi_0", &nsigTPC_Pi_0);
myTree->SetBranchAddress("nsigTPC_Pi_1", &nsigTPC_Pi_1);
myTree->SetBranchAddress("nsigTPC_Pi_2", &nsigTPC_Pi_2);
myTree->SetBranchAddress("nsigTPC_K_0", &nsigTPC_K_0);
myTree->SetBranchAddress("nsigTPC_K_1", &nsigTPC_K_1);
myTree->SetBranchAddress("nsigTPC_K_2", &nsigTPC_K_2);
myTree->SetBranchAddress("nsigTPC_Pr_0", &nsigTPC_Pr_0);
myTree->SetBranchAddress("nsigTPC_Pr_1", &nsigTPC_Pr_1);
myTree->SetBranchAddress("nsigTPC_Pr_2", &nsigTPC_Pr_2);
myTree->SetBranchAddress("nsigTOF_Pi_0", &nsigTOF_Pi_0);
myTree->SetBranchAddress("nsigTOF_Pi_1", &nsigTOF_Pi_1);
myTree->SetBranchAddress("nsigTOF_Pi_2", &nsigTOF_Pi_2);
myTree->SetBranchAddress("nsigTOF_K_0", &nsigTOF_K_0);
myTree->SetBranchAddress("nsigTOF_K_1", &nsigTOF_K_1);
myTree->SetBranchAddress("nsigTOF_K_2", &nsigTOF_K_2);
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
newTree->Branch("nsigTPC_Pi_0", &nsigTPC_Pi_0, "nsigTPC_Pi_0/F");
newTree->Branch("nsigTPC_Pi_1", &nsigTPC_Pi_1, "nsigTPC_Pi_1/F");
newTree->Branch("nsigTPC_Pi_2", &nsigTPC_Pi_2, "nsigTPC_Pi_2/F");
newTree->Branch("nsigTPC_K_0", &nsigTPC_K_0, "nsigTPC_K_0/F");
newTree->Branch("nsigTPC_K_1", &nsigTPC_K_1, "nsigTPC_K_1/F");
newTree->Branch("nsigTPC_K_2", &nsigTPC_K_2, "nsigTPC_K_2/F");
newTree->Branch("nsigTPC_Pr_0", &nsigTPC_Pr_0, "nsigTPC_Pr_0/F");
newTree->Branch("nsigTPC_Pr_1", &nsigTPC_Pr_1, "nsigTPC_Pr_1/F");
newTree->Branch("nsigTPC_Pr_2", &nsigTPC_Pr_2, "nsigTPC_Pr_2/F");
newTree->Branch("nsigTOF_Pi_0", &nsigTOF_Pi_0, "nsigTOF_Pi_0/F");
newTree->Branch("nsigTOF_Pi_1", &nsigTOF_Pi_1, "nsigTOF_Pi_1/F");
newTree->Branch("nsigTOF_Pi_2", &nsigTOF_Pi_2, "nsigTOF_Pi_2/F");
newTree->Branch("nsigTOF_K_0", &nsigTOF_K_0, "nsigTOF_K_0/F");
newTree->Branch("nsigTOF_K_1", &nsigTOF_K_1, "nsigTOF_K_1/F");
newTree->Branch("nsigTOF_K_2", &nsigTOF_K_2, "nsigTOF_K_2/F");
newTree->Branch("sig_vert", &sig_vert, "sig_vert/F");
newTree->Branch("max_norm_d0d0exp", &max_norm_d0d0exp, "max_norm_d0d0exp/F");
newTree->Branch("imp_par_prong0", &imp_par_prong0, "imp_par_prong0/F");
newTree->Branch("imp_par_prong1", &imp_par_prong1, "imp_par_prong1/F");
newTree->Branch("imp_par_prong2", &imp_par_prong2, "imp_par_prong2/F");

Long64_t nEntries = myTree->GetEntries();
for (Long64_t iEntry = 0; iEntry < nEntries; iEntry++) {
    var1 = 0; var2 = 0; var3 = 0; // set branch addresses to nullptr
    myTree->GetEntry(iEntry);
    
    if (pt_cand > 1 && pt_cand < 2) {
        newTree->Fill();
    }
}

  
  

    newFile->Write();
    newFile->Close();
    file->Close();

    return 0;
}

/*
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
*/

void merge(const std::string& dir_path) {
    TFile *mergedFile = TFile::Open("mergedAnalysisResults_2.root", "RECREATE");
    TChain *mergedTree = new TChain("treeMLLc_new");

    std::vector<std::string> files;
    for (const auto & entry : std::filesystem::directory_iterator(dir_path)) {
        if(entry.path().extension() == ".root") { // check if the file extension is .root
            files.push_back(entry.path());
        }
    }
  
    // Add the output files from the previous conversion code to the chain
    for(const auto& file : files) {
        mergedTree->Add(file.c_str());
    }

    // Copy the tree to the merged output file
    TTree *newTree = mergedTree->CloneTree();
    newTree->Write();

    mergedFile->Close();
}




int cloning(std::string filename){


 //   TFile *file = TFile::Open("AnalysisResults_2835621768.root");

 //   TDirectory *myDir = (TDirectory *)file->Get("PWGHF_D2H_NonPromptLctopKpiLoose_0_100");\
    
    
        TFile *file = TFile::Open(filename.c_str());
    if (!file || file->IsZombie()) {
    std::cout << "Failed to open file: " << filename << std::endl;
    return 0;
}
    TDirectory *myDir = (TDirectory *)file->Get("PWGHF_D2H_NonPromptLctopKpiLoose_MC");\
    
    
    if (!myDir) {
    std::cout << "Failed to find directory: PWGHF_D2H_NonPromptLctopKpiLoose_0_100 in file: " << filename << std::endl;
    return 0;
}



     std::string prefix = "all_variables_";
     std::filesystem::path filePath(file->GetName());
     std::string name = filePath.filename().string();
      std::string newFilename = prefix + name;
   //  std::string newFilename = prefix+file->GetName();
      cout<<newFilename.c_str()<<endl;
//return 0;
  
    TFile *newFile = TFile::Open(newFilename.c_str(), "RECREATE");

TTree *myTree = (TTree *)myDir->Get("treeMLLc");
TTree *newTree = myTree->CloneTree(); // Clones all branches and entries

newTree->SetName("treeMLLc_new"); // Set the new name for the tree
newTree->SetTitle("New tree with selected branches"); // Set the new title for the tree4

    newFile->Write();
    newFile->Close();
    file->Close();

  return 0;





}




void convert_all_files(std::string directory) {
    DIR *dir;
    cout<<"part0"<<endl;
    struct dirent *ent;
    if ((dir = opendir(directory.c_str())) != NULL) {
        cout<<"part1"<<endl;
        while ((ent = readdir(dir)) != NULL) {
            std::string filename = ent->d_name;
            if (filename.find(".root") != std::string::npos) { // check if the file is a root file
                std::string full_filename = directory + "/" + filename; // construct full path
                convert(full_filename); // call your function
                //cloning(full_filename);
            }
        }
        closedir(dir);
    } else {
        std::cout << "Could not open directory " << directory << std::endl;
    }
}


int myfunction() {
        
    convert_all_files("/Users/oveis/Desktop/child1_extra/2/");
    merge("/Users/oveis/Desktop/child1_extra/temp/");
    return 0;
}

