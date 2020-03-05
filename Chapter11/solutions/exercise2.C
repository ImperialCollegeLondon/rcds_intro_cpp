// Creating esercizio2

void exercise2() {

  // Create variables
  TCanvas *c = new TCanvas("c", "Exercise 2", 800, 500);
  TH1F *h1 = new TH1F("h1", "Exercise 2", 100, -4, 4);

  // Fill the histogram with a gaussian
  h1->FillRandom("gaus", 5000);
  h1->SetFillColor(kOrange);
  h1->SetLineColor(kBlue);
  h1->GetXaxis()->SetTitle("x");
  h1->GetYaxis()->SetTitle("frequency");
  h1->Draw();

  // Save plot to disk
  c->SaveAs("exercise2.png");

}