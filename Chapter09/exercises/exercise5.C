// ROOT macro

void exercise5() {

  // Read data form file
  const int n = 100;
  double x[n], y[n], y2[n];

  fstream f;
  f.open("../data.dat", ios::in);
  if (!f.good())
    {
      cerr << "Error opening file" << endl;
      return;
    }

  for (int i = 0; i < n; i++)
    f >> x[i] >> y[i] >> y2[i];

  f.close();
  
  // Create TCanvas
  TCanvas *c1 = new TCanvas("c1", "Exercise 5A", 600, 400);

  // Create TGraph
  TGraph *g1 = new TGraph(n,x,y);
  g1->SetTitle("(x,y)");
  g1->GetXaxis()->SetTitle("x");
  g1->GetYaxis()->SetTitle("y");  
  g1->Draw("A*");
  g1->Fit("pol1");

  c1->SaveAs("ex5a.png");
  
  // creo oggetto TCanvas
  TCanvas *c2 = new TCanvas("c2", "Exercise 5B", 600, 400);

  // Create TGraph
  TGraph *g2 = new TGraph(n,x,y2);
  g2->SetTitle("(x,y2)");
  g2->GetXaxis()->SetTitle("x");
  g2->GetYaxis()->SetTitle("y2");  
  g2->Draw("A*");
  
  TF1 *f1 = new TF1("f1", "[0]*x^2 + [1]*x + [2]", 0, 1);
  g2->Fit("f1");

  c2->SaveAs("ex5b.png");

}