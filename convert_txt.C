void convert_txt(){
  TFile *file1 = new TFile("uboone_70k_1D.root");
  TGraph *gu_1D_c = (TGraph*)file1->Get("u_1D_c");
  TGraph *gv_1D_c = (TGraph*)file1->Get("v_1D_c");
  TGraph *gw_1D_c = (TGraph*)file1->Get("w_1D_c");

  ofstream outfile("data_70_ROI_11.txt");  
  outfile << "Double_t u_1D_c_x[5000] = {";
  for (Int_t i=0;i!=5000;i++){
    Double_t x,y;
    gu_1D_c->GetPoint(i,x,y);
    if (i==gu_1D_c->GetN()-1){
      outfile << x;
    }else{
      outfile << x << ",";
    }
  }
  outfile << "};" << endl;


  outfile << "Double_t u_1D_c_y[5000] = {";
  for (Int_t i=0;i!=5000;i++){
    Double_t x,y;
    gu_1D_c->GetPoint(i,x,y);
    
    y/= 1.15;

    if (i==gu_1D_c->GetN()-1){
      outfile << y;
    }else{
      outfile << y << ",";
    }
  }
  outfile << "};" << endl;


  outfile << "Double_t v_1D_c_x[5000] = {";
  for (Int_t i=0;i!=5000;i++){
    Double_t x,y;
    gv_1D_c->GetPoint(i,x,y);

   

    if (i==gv_1D_c->GetN()-1){
      outfile << x;
    }else{
      outfile << x << ",";
    }
  }
  outfile << "};" << endl;


  outfile << "Double_t v_1D_c_y[5000] = {";
  for (Int_t i=0;i!=5000;i++){
    Double_t x,y;
    gv_1D_c->GetPoint(i,x,y);

    y/= 1.15;
    
    if (i==gv_1D_c->GetN()-1){
      outfile << y;
    }else{
      outfile << y << ",";
    }
  }
  outfile << "};" << endl;


    

  outfile << "Double_t w_1D_c_x[5000] = {";
  for (Int_t i=0;i!=5000;i++){
    Double_t x,y;
    gw_1D_c->GetPoint(i,x,y);
    if (i==gw_1D_c->GetN()-1){
      outfile << x;
    }else{
      outfile << x << ",";
    }
  }
  outfile << "};" << endl;


  outfile << "Double_t w_1D_c_y[5000] = {";
  for (Int_t i=0;i!=5000;i++){
    Double_t x,y;
    gw_1D_c->GetPoint(i,x,y);

    y/= 1.15;

    if (i==gw_1D_c->GetN()-1){
      outfile << y;
    }else{
      outfile << y << ",";
    }
  }
  outfile << "};" << endl;


  
  TFile *file2 = new TFile("uboone_70k_2D_11.root");
  TGraph **gu_2D_g = new TGraph*[11];
  TGraph **gv_2D_g = new TGraph*[11];
  TGraph **gw_2D_g = new TGraph*[11];
  for (Int_t i=0;i!=11;i++){
    gu_2D_g[i] = (TGraph*)file2->Get(Form("u_2D_%d_g",i));
    gv_2D_g[i] = (TGraph*)file2->Get(Form("v_2D_%d_g",i));
    gw_2D_g[i] = (TGraph*)file2->Get(Form("w_2D_%d_g",i));
  }

  for (Int_t j=0;j!=11;j++){
    outfile << Form("Double_t u_2D_g_%d_x[5000] = {",j);
    for (Int_t i=0;i!=5000;i++){
      Double_t x,y;
      gu_2D_g[j]->GetPoint(i,x,y);
      if (i==gu_2D_g[j]->GetN()-1){
	outfile << x;
      }else{
	outfile << x << ",";
      }
    }
    outfile << "};" << endl;
    
    outfile << Form("Double_t u_2D_g_%d_y[5000] = {",j);
    for (Int_t i=0;i!=5000;i++){
      Double_t x,y;
      gu_2D_g[j]->GetPoint(i,x,y);
      if (i==gu_2D_g[j]->GetN()-1){
	outfile << y;
      }else{
	outfile << y << ",";
      }
    }
    outfile << "};" << endl;



    outfile << Form("Double_t v_2D_g_%d_x[5000] = {",j);
    for (Int_t i=0;i!=5000;i++){
      Double_t x,y;
      gv_2D_g[j]->GetPoint(i,x,y);
      if (i==gv_2D_g[j]->GetN()-1){
	outfile << x;
      }else{
	outfile << x << ",";
      }
    }
    outfile << "};" << endl;
    
    outfile << Form("Double_t v_2D_g_%d_y[5000] = {",j);
    for (Int_t i=0;i!=5000;i++){
      Double_t x,y;
      gv_2D_g[j]->GetPoint(i,x,y);
      if (i==gv_2D_g[j]->GetN()-1){
	outfile << y;
      }else{
	outfile << y << ",";
      }
    }
    outfile << "};" << endl;



    outfile << Form("Double_t w_2D_g_%d_x[5000] = {",j);
    for (Int_t i=0;i!=5000;i++){
      Double_t x,y;
      gw_2D_g[j]->GetPoint(i,x,y);
      if (i==gw_2D_g[j]->GetN()-1){
	outfile << x;
      }else{
	outfile << x << ",";
      }
    }
    outfile << "};" << endl;
    
    outfile << Form("Double_t w_2D_g_%d_y[5000] = {",j);
    for (Int_t i=0;i!=5000;i++){
      Double_t x,y;
      gw_2D_g[j]->GetPoint(i,x,y);
      if (i==gw_2D_g[j]->GetN()-1){
	outfile << y;
      }else{
	outfile << y << ",";
      }
    }
    outfile << "};" << endl;
  }

  






  outfile.close();

}
