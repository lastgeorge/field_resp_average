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

void tesst1(){
  TF1 *f3 = new TF1("func3",response,0,10,2);
  f3->SetParameters(10.*1.012,2.0); // 14mV/fC for now with 0.5 us shaping time
    
  TH1F *h1 = new TH1F("h1","h1",1000,0.,10);
  for (Int_t i=0;i!=1000;i++){
    Double_t x = h1->GetBinCenter(i+1);
    h1->SetBinContent(i+1,f3->Eval(x));
  }
  h1->Draw();
  h1->Rebin(50);
  h1->Scale(1./50.);
  cout << h1->GetSum() << endl;
}
