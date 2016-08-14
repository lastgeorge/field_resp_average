void compare_1d_2d(){
  TFile *file1 = new TFile("uboone_70k_1D.root");
  TFile *file2 = new TFile("uboone_70k_2D_11.root");
  TGraph *gw1 = (TGraph*)file1->Get("w_1D_c");
  TGraph *gw2 = (TGraph*)file2->Get("w_2D_0_g");
  
  gw1->Draw("AL");
  gw2->Draw("Lsame");
  gw2->SetLineColor(2);

  Double_t sum = 0, sum1 = 0;
  for (Int_t i=0;i!=5000;i++){
    Double_t x = -35 + 50./5000.*i;
    sum += gw1->Eval(x);
    sum1 += gw2->Eval(x);
  }
  cout << sum << " " << sum1 << endl;

}
