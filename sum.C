double response(double *x, double *par){
double f = 4.31054*exp(-2.94809*x[0]/par[1])*par[0]-2.6202*exp(-2.82833*x[0]/par[1])*cos(1.19361*x[0]/par[1])*par[0]
              -2.6202*exp(-2.82833*x[0]/par[1])*cos(1.19361*x[0]/par[1])*cos(2.38722*x[0]/par[1])*par[0]
                    +0.464924*exp(-2.40318*x[0]/par[1])*cos(2.5928*x[0]/par[1])*par[0]
                          +0.464924*exp(-2.40318*x[0]/par[1])*cos(2.5928*x[0]/par[1])*cos(5.18561*x[0]/par[1])*par[0]
                                +0.762456*exp(-2.82833*x[0]/par[1])*sin(1.19361*x[0]/par[1])*par[0]
                                      -0.762456*exp(-2.82833*x[0]/par[1])*cos(2.38722*x[0]/par[1])*sin(1.19361*x[0]/par[1])*par[0]
                                            +0.762456*exp(-2.82833*x[0]/par[1])*cos(1.19361*x[0]/par[1])*sin(2.38722*x[0]/par[1])*par[0]
                                                  -2.6202*exp(-2.82833*x[0]/par[1])*sin(1.19361*x[0]/par[1])*sin(2.38722*x[0]/par[1])*par[0] 
                                                        -0.327684*exp(-2.40318*x[0]/par[1])*sin(2.5928*x[0]/par[1])*par[0] + 
                                                              +0.327684*exp(-2.40318*x[0]/par[1])*cos(5.18561*x[0]/par[1])*sin(2.5928*x[0]/par[1])*par[0]
                                                                    -0.327684*exp(-2.40318*x[0]/par[1])*cos(2.5928*x[0]/par[1])*sin(5.18561*x[0]/par[1])*par[0]
                                                                          +0.464924*exp(-2.40318*x[0]/par[1])*sin(2.5928*x[0]/par[1])*sin(5.18561*x[0]/par[1])*par[0];

 if (x[0] >0&&x[0] < 10){
    return f;
 }else{
   return 0;
 }
}


void sum(){
  TFile *file = new TFile("uboone.root");
  TGraph **gu = new TGraph*[126];
  TGraph **gv = new TGraph*[126];
  TGraph **gwc = new TGraph*[126];
  TGraph **gwi = new TGraph*[126];
  TGraph **gw = new TGraph*[126];
  for (Int_t i=0;i!=126;i++){
    gu[i] = (TGraph*)file->Get(Form("guc_%d",i+1));
    gv[i] = (TGraph*)file->Get(Form("gvc_%d",i+1));
    gwi[i] = (TGraph*)file->Get(Form("gwi_%d",i+1));
    gwc[i] = (TGraph*)file->Get(Form("gwc_%d",i+1));
    
    gw[i] = new TGraph();
    for (Int_t j=0;j!=gwi[i]->GetN();j++){
      Double_t x,y;
      gwi[i]->GetPoint(j,x,y);
      y+= gwc[i]->Eval(x);
      gw[i]->SetPoint(j,x,y);
    }
    
  }
  Int_t nwires = 21;
  Int_t npoints = 6;

  TGraph **gu_ave = new TGraph*[11];
  TGraph **gv_ave = new TGraph*[11];
  TGraph **gw_ave = new TGraph*[11];
  
  // for (Int_t i=0;i!=gu[0]->GetN();i++){
  //   Double_t x,y;
  //   gu[0]->GetPoint(i,x,y);
  //   y = (gu[0]->Eval(x) + gu[1]->Eval(x) + gu[2]->Eval(x) + gu[3]->Eval(x) + gu[4]->Eval(x))/5.;
  //   x -= 57;
  //   gu_ave->SetPoint(i,x,y);
  // }

  // for (Int_t i=0;i!=gv[0]->GetN();i++){
  //   Double_t x,y;
  //   gv[0]->GetPoint(i,x,y);
  //   y = (gv[0]->Eval(x) + gv[1]->Eval(x) + gv[2]->Eval(x) + gv[3]->Eval(x) + gv[4]->Eval(x))/5.;
  //   x -= 57;
  //   gv_ave->SetPoint(i,x,y);
  // }

  // for (Int_t i=0;i!=gw[0]->GetN();i++){
  //   Double_t x,y;
  //   gw[0]->GetPoint(i,x,y);
    
  //   y = (gw[0*21+11-1]->Eval(x)*0.5 + gw[1*21+11-1]->Eval(x) + gw[2*21+11-1]->Eval(x) + gw[3*21+11-1]->Eval(x) + gw[4*21+11-1]->Eval(x) + gw[5*21+11-1]->Eval(x)*0.5)/5.;
  //   x -= 57;
  //   gw_ave->SetPoint(i,x,y);
  // }
  //  gw_ave->Draw();

  for (Int_t j=0;j!=11;j++){
    gu_ave[j] = new TGraph();
    gv_ave[j] = new TGraph();
    gw_ave[j] = new TGraph();
  
    for (Int_t i=0;i!=gu[0]->GetN();i++){
      Double_t x,y;
      gu[0]->GetPoint(i,x,y);
      
      y = (gu[0*21+(11-j)-1]->Eval(x)*0.5 + gu[1*21+(11-j)-1]->Eval(x) + gu[2*21+(11-j)-1]->Eval(x) + gu[3*21+(11-j)-1]->Eval(x) + gu[4*21+(11-j)-1]->Eval(x) + gu[5*21+(11-j)-1]->Eval(x)*0.5)/5.;
      y += (gu[0*21+(11+j)-1]->Eval(x)*0.5 + gu[1*21+(11+j)-1]->Eval(x) + gu[2*21+(11+j)-1]->Eval(x) + gu[3*21+(11+j)-1]->Eval(x) + gu[4*21+(11+j)-1]->Eval(x) + gu[5*21+(11+j)-1]->Eval(x)*0.5)/5.;
      y/=2.;

      x -= 57;
      gu_ave[j]->SetPoint(i,x,y);
    }



    for (Int_t i=0;i!=gv[0]->GetN();i++){
      Double_t x,y;
      gv[0]->GetPoint(i,x,y);
      
      y = (gv[0*21+(11-j)-1]->Eval(x)*0.5 + gv[1*21+(11-j)-1]->Eval(x) + gv[2*21+(11-j)-1]->Eval(x) + gv[3*21+(11-j)-1]->Eval(x) + gv[4*21+(11-j)-1]->Eval(x) + gv[5*21+(11-j)-1]->Eval(x)*0.5)/5.;
      y += (gv[0*21+(11+j)-1]->Eval(x)*0.5 + gv[1*21+(11+j)-1]->Eval(x) + gv[2*21+(11+j)-1]->Eval(x) + gv[3*21+(11+j)-1]->Eval(x) + gv[4*21+(11+j)-1]->Eval(x) + gv[5*21+(11+j)-1]->Eval(x)*0.5)/5.;
      y/=2.;

      x -= 57;
      gv_ave[j]->SetPoint(i,x,y);
    }


    for (Int_t i=0;i!=gw[0]->GetN();i++){
      Double_t x,y;
      gw[0]->GetPoint(i,x,y);
      
      y = (gw[0*21+(11-j)-1]->Eval(x)*0.5 + gw[1*21+(11-j)-1]->Eval(x) + gw[2*21+(11-j)-1]->Eval(x) + gw[3*21+(11-j)-1]->Eval(x) + gw[4*21+(11-j)-1]->Eval(x) + gw[5*21+(11-j)-1]->Eval(x)*0.5)/5.;
      y += (gw[0*21+(11+j)-1]->Eval(x)*0.5 + gw[1*21+(11+j)-1]->Eval(x) + gw[2*21+(11+j)-1]->Eval(x) + gw[3*21+(11+j)-1]->Eval(x) + gw[4*21+(11+j)-1]->Eval(x) + gw[5*21+(11+j)-1]->Eval(x)*0.5)/5.;
      y/=2.;

      x -= 57;
      gw_ave[j]->SetPoint(i,x,y);
    }

  }


  gw_ave[0]->GetYaxis()->SetRangeUser(-0.5,0.1);
  // go through each wire ... 
  gw_ave[0]->SetLineColor(1);

  // gu_ave[10]->Draw("same");
  // gv_ave[10]->Draw("same");
  // gu_ave[10]->SetLineColor(2);
  // gv_ave[10]->SetLineColor(4);
  
  

  // Smear with response function ... 
  TF1 *f3 = new TF1("func3",response,0,10,2);
  f3->SetParameters(10.*1.012,2.0); // 14mV/fC for now with 0.5 us shaping time
    
  // Do convolution 
  // TH1F *hw = new TH1F("hw","hw",5000,-60,40);
  TH1F *her = new TH1F("her","her",5000,0,100);
  
  TH1F **hu = new TH1F*[11];
  TH1F **hv = new TH1F*[11];
  TH1F **hw = new TH1F*[11];
  for (Int_t i=0;i!=11;i++){
    hu[i] = new TH1F(Form("hu_%d",i),Form("hu_%d",i),5000,-60,40);
    hv[i] = new TH1F(Form("hv_%d",i),Form("hv_%d",i),5000,-60,40);
    hw[i] = new TH1F(Form("hw_%d",i),Form("hw_%d",i),5000,-60,40);
  }
  

  for (Int_t i=0;i!=her->GetNbinsX();i++){
    Double_t x =  her->GetBinCenter(i+1);
    her->SetBinContent(i+1,f3->Eval(x));
    x = hw[0]->GetBinCenter(i+1);
    for (Int_t j=0;j!=11;j++){
      Double_t content = gw_ave[j]->Eval(x);
      if (x < -57) content = 0;
      hw[j]->SetBinContent(i+1,content);
      content = gu_ave[j]->Eval(x);
      if (x < -57) content = 0;
      hu[j]->SetBinContent(i+1,content);
      content = gv_ave[j]->Eval(x);
      if (x < -57) content = 0;
      hv[j]->SetBinContent(i+1,content);
    }
  }
  
  Double_t norm = fabs(hw[0]->GetSum());
  std::cout << norm << std::endl;
  // hw->Scale(1./norm);
  for (Int_t i=0;i!=11;i++){
    hu[i]->Scale(1./norm);
    hv[i]->Scale(1./norm);
    hw[i]->Scale(1./norm);
  }

  TVirtualFFT::SetTransform(0);
  TH1 *hmr = 0;
  TH1 *hpr = 0;
  hmr = her->FFT(hmr,"MAG");
  hpr = her->FFT(hpr,"PH");
  
  Int_t  n  =5000;
  TVirtualFFT *ifft = TVirtualFFT::FFT(1,&n,"C2R M K");
  Double_t value_re[5000];
  Double_t value_im[5000];
  TH1 *fb = 0;
  TH1 *hm = 0;
  TH1 *hp = 0;

  for (Int_t i=0;i!=11;i++){
    // Now deal with U plane 
    delete hm;
    delete hp;
    hm = 0;
    hp = 0;
    hm = hu[i]->FFT(hm,"MAG");
    hp = hu[i]->FFT(hp,"PH");
    for (Int_t j=0;j!=n;j++){
      Double_t rho = hm->GetBinContent(j+1) * hmr->GetBinContent(j+1);
      Double_t phi = hp->GetBinContent(j+1) + hpr->GetBinContent(j+1);
      value_re[j] = rho*cos(phi)/n;
      value_im[j] = rho*sin(phi)/n;
    }
    ifft->SetPointsComplex(value_re,value_im);
    ifft->Transform();
    delete fb;
    fb = 0;
    fb = TH1::TransformHisto(ifft,fb,"Re");
    for (Int_t j=0;j!=n;j++){
      hu[i]->SetBinContent(j+1,fb->GetBinContent(j+1));
    }
    
    // Now deal with V plane
    delete hm;
    delete hp;
    hm = 0;
    hp = 0;
    hm = hv[i]->FFT(hm,"MAG");
    hp = hv[i]->FFT(hp,"PH");
    for (Int_t j=0;j!=n;j++){
      Double_t rho = hm->GetBinContent(j+1) * hmr->GetBinContent(j+1);
      Double_t phi = hp->GetBinContent(j+1) + hpr->GetBinContent(j+1);
      value_re[j] = rho*cos(phi)/n;
      value_im[j] = rho*sin(phi)/n;
    }
    ifft->SetPointsComplex(value_re,value_im);
    ifft->Transform();
    delete fb;
    fb = 0;
    fb = TH1::TransformHisto(ifft,fb,"Re");
    for (Int_t j=0;j!=n;j++){
      hv[i]->SetBinContent(j+1,fb->GetBinContent(j+1));
    }


    // Now deal with V plane
    delete hm;
    delete hp;
    hm = 0;
    hp = 0;
    hm = hw[i]->FFT(hm,"MAG");
    hp = hw[i]->FFT(hp,"PH");
    for (Int_t j=0;j!=n;j++){
      Double_t rho = hm->GetBinContent(j+1) * hmr->GetBinContent(j+1);
      Double_t phi = hp->GetBinContent(j+1) + hpr->GetBinContent(j+1);
      value_re[j] = rho*cos(phi)/n;
      value_im[j] = rho*sin(phi)/n;
    }
    ifft->SetPointsComplex(value_re,value_im);
    ifft->Transform();
    delete fb;
    fb = 0;
    fb = TH1::TransformHisto(ifft,fb,"Re");
    for (Int_t j=0;j!=n;j++){
      hw[i]->SetBinContent(j+1,fb->GetBinContent(j+1));
    }

  }

  // // Now deal with W plane
  // delete hm;
  // delete hp;
  // hm = 0;
  // hp = 0;
  // hm = hw->FFT(hm,"MAG");
  // hp = hw->FFT(hp,"PH");
  // for (Int_t j=0;j!=n;j++){
  //   Double_t rho = hm->GetBinContent(j+1) * hmr->GetBinContent(j+1);
  //   Double_t phi = hp->GetBinContent(j+1) + hpr->GetBinContent(j+1);
  //   value_re[j] = rho*cos(phi)/n;
  //   value_im[j] = rho*sin(phi)/n;
  // }
  // ifft->SetPointsComplex(value_re,value_im);
  // ifft->Transform();
  // delete fb;
  // fb = 0;
  // fb = TH1::TransformHisto(ifft,fb,"Re");
  // for (Int_t j=0;j!=n;j++){
  //   hw->SetBinContent(j+1,fb->GetBinContent(j+1));
  // }
  
  TCanvas *c1 = new TCanvas("c1","c1",800,800);
  c1->Divide(2,2);
  c1->cd(1);
  hw[0]->Draw();
  hw[0]->SetTitle("");
  hw[0]->GetXaxis()->SetTitle("Time (#mus)");

  hu[0]->Draw("same");
  hv[0]->Draw("same");
  
  hw[0]->SetLineColor(1);
  hu[0]->SetLineColor(2);
  hv[0]->SetLineColor(4);
  hw[0]->GetYaxis()->SetRangeUser(-12,7);
  
  TLegend *le1 = new TLegend(0.6,0.6,0.89,0.89);
  le1->SetFillColor(10);
  le1->AddEntry(hu[0],"U Ind. plane","l");
  le1->AddEntry(hv[0],"V Ind. plane","l");
  le1->AddEntry(hw[0],"W Col. plane","l");
  le1->Draw();

  c1->cd(2);
  hu[0]->Draw();
  hu[0]->SetTitle("U plane");
  hu[0]->GetXaxis()->SetTitle("Time (#mus)");

  for (Int_t j=0;j!=10;j++){
    hu[j+1]->Draw("same");
  }

  c1->cd(3);
  hv[0]->Draw();
  hv[0]->SetTitle("V plane");
  hv[0]->GetXaxis()->SetTitle("Time (#mus)");
  for (Int_t j=0;j!=10;j++){
    hv[j+1]->Draw("same");
  }

  c1->cd(4);
  TH1F *htest_u = (TH1F*)hu[0]->Clone("htest_u");
  TH1F *htest1_u = (TH1F*)hu[0]->Clone("htest1_u");

  TH1F *htest_v = (TH1F*)hv[0]->Clone("htest_v");
  TH1F *htest1_v = (TH1F*)hv[0]->Clone("htest1_v");
  
  for (Int_t i=0;i!=10;i++){
    htest_u->Add(hu[i+1],2);
    htest_v->Add(hv[i+1],2);
    if (i<=3){
      htest1_u->Add(hu[i+1],2);
      htest1_v->Add(hv[i+1],2);
    }
    
  }
  
  
  htest_u->Draw();
  htest1_u->Draw("same");
  htest_v->Draw("same");
  htest1_v->Draw("same");
  
  htest_u->SetLineColor(1);
  htest1_u->SetLineColor(2);
  htest_v->SetLineColor(4);
  htest1_v->SetLineColor(6);
  
  htest_u->GetYaxis()->SetRangeUser(-10,10);

  TLegend *le2 = new TLegend(0.6,0.6,0.89,0.89);
  le2->SetFillColor(10);
  le2->SetHeader("Parallel Track");
  le2->AddEntry(htest_u,"U #pm 10 wires","l");
  le2->AddEntry(htest1_u,"U #pm 3 wires","l");
  le2->AddEntry(htest_v,"V #pm 10 wires","l");
  le2->AddEntry(htest1_v,"V #pm 3 wires","l");
  le2->Draw();
  
  f3->Draw();

  TFile *file1 = new TFile("ave_res.root","RECREATE");
  for (Int_t i=0;i!=11;i++){
    hu[i]->SetDirectory(file1);
    hv[i]->SetDirectory(file1);
    hw[i]->SetDirectory(file1);
  }
  
  file1->Write();
  file1->Close();



 

  
}
