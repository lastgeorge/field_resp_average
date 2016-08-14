void compare(){
#include "data_70_ROI.txt"
  // TGraph **gu_2D_g = new TGraph*[4];
  // gu_2D_g[0] = new TGraph(5000,u_2D_g_0_x,u_2D_g_0_y);
  // gu_2D_g[1] = new TGraph(5000,u_2D_g_1_x,u_2D_g_1_y);
  // gu_2D_g[2] = new TGraph(5000,u_2D_g_2_x,u_2D_g_2_y);
  // gu_2D_g[3] = new TGraph(5000,u_2D_g_3_x,u_2D_g_3_y);
  // TGraph **gv_2D_g = new TGraph*[4];
  // gv_2D_g[0] = new TGraph(5000,v_2D_g_0_x,v_2D_g_0_y);
  // gv_2D_g[1] = new TGraph(5000,v_2D_g_1_x,v_2D_g_1_y);
  // gv_2D_g[2] = new TGraph(5000,v_2D_g_2_x,v_2D_g_2_y);
  // gv_2D_g[3] = new TGraph(5000,v_2D_g_3_x,v_2D_g_3_y);
  TGraph *gw_1D_g = new TGraph(5000,w_1D_g_x,w_1D_g_y);
  TGraph *gu_1D_c = new TGraph(5000,u_1D_c_x,u_1D_c_y);
  TGraph *gv_1D_c = new TGraph(5000,v_1D_c_x,v_1D_c_y);


  TFile *file = new TFile("ave_res.root");
  //TH1F *hw = (TH1F*)file->Get("hw");
  TH1F **hu = new TH1F*[11];
  TH1F **hv = new TH1F*[11];
  TH1F **hw = new TH1F*[11];
  for (Int_t i=0;i!=11;i++){
    hu[i] = (TH1F*)file->Get(Form("hu_%d",i));
    hv[i] = (TH1F*)file->Get(Form("hv_%d",i));
    hw[i] = (TH1F*)file->Get(Form("hw_%d",i));
  }
  
  Double_t time_offset = 24.1;
  Double_t factor = (-1) / (6241.51);//*1.1442 ;
  //  hw->Draw();

  //  TGraph *gw = new TGraph();
  TGraph **gu = new TGraph*[11];
  TGraph **gv = new TGraph*[11];
  TGraph **gw = new TGraph*[11];
  for (Int_t i=0;i!=11;i++){
    gu[i] = new TGraph();
    gv[i] = new TGraph();
    gw[i] = new TGraph();
  }
  
  for (Int_t i=0;i!=11;i++){
    
    // fill a TGraph from a new histogram
    for (Int_t j=0;j!=hu[i]->GetNbinsX();j++){
      Double_t x = hu[i]->GetBinCenter(j+1);
      Double_t y = hu[i]->GetBinContent(j+1);
      x -= time_offset;
      y *= factor;
      gu[i]->SetPoint(j,x,y);
      
    }
    
    for (Int_t j=0;j!=hv[i]->GetNbinsX();j++){
      Double_t x = hv[i]->GetBinCenter(j+1);
      Double_t y = hv[i]->GetBinContent(j+1);
      x -= time_offset;
      y *= factor;
      gv[i]->SetPoint(j,x,y);
    }
    
     for (Int_t j=0;j!=hw[i]->GetNbinsX();j++){
      Double_t x = hw[i]->GetBinCenter(j+1);
      Double_t y = hw[i]->GetBinContent(j+1);
      x -= time_offset;
      y *= factor;
      gw[i]->SetPoint(j,x,y);
    }
    
  }
 
  // for (Int_t j=0;j!=hw->GetNbinsX();j++){
  //     Double_t x = hw->GetBinCenter(j+1);
  //     Double_t y = hw->GetBinContent(j+1);
  //     x -= time_offset;
  //     y *= factor;
  //     gw->SetPoint(j,x,y);
  //   }
  
 
  gu[0]->Draw("AL");
  gv[0]->Draw("Lsame");
  gw[0]->Draw("Lsame");
  gw_1D_g->Draw("Lsame");
  gu[0]->GetYaxis()->SetRangeUser(-0.05e-3,0.2e-3);
  gw_1D_g->SetLineColor(2);
  gw[0]->SetLineColor(4);

  Double_t sum = 0, sum1 = 0;
  for (Int_t i=0;i!=gw_1D_g->GetN();i++){
    Double_t x,y;
    gw_1D_g->GetPoint(i,x,y);
    sum += y;
    // cout << x << " ";
    // gw[0]->GetPoint(i,x,y);
      
    sum1+=gw[0]->Eval(x);
    //    cout << x << endl;
  }
  cout << sum << " " << sum1 << endl;


  TFile *file1 = new TFile("uboone_70k_2D_11.root","RECREATE");
  //gw->Write("w_1D_g");
  for (Int_t i=0;i!=11;i++){
    gu[i]->Write(Form("u_2D_%d_g",i));
    gv[i]->Write(Form("v_2D_%d_g",i));
    gw[i]->Write(Form("w_2D_%d_g",i));
  }
  file1->Write();
  file1->Close();

  
}
