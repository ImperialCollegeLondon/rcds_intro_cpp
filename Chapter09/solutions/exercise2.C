// ROOT macro

void exercise2() {

  // Crete TF1 object
  TF1 *f1 = new TF1("f1", "-sin(x*x)/x + 0.01 * x*x", -3, 3);

  // Modify title and axis
  f1->SetTitle("Exercise 2");
  f1->GetXaxis()->SetTitle("x");
  f1->GetYaxis()->SetTitle("y");

  // Modify color
  f1->SetLineColor(kBlue);

  // Design
  f1->Draw();

  // Build the function 0.1*sin(4*x)/x
  TF1 *f2 = new TF1("f2", "0.1*sin(4*x)/x", -3, 3);
  f2->Draw("same");

  // Build the function 0.5*x
  TF1 *f3 = new TF1("f3", "0.5*x", -3, 3);
  f3->SetLineColor(kGreen);
  f3->Draw("same");

}