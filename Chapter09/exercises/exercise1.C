// ROOT macro

void exercise1() {

  // Create TF1 object
  TF1 *f1 = new TF1("f1", "-sin(x*x)/x + 0.01 * x*x", -3, 3);

  // Modify title and axis
  f1->SetTitle("Exercise 1");
  f1->GetXaxis()->SetTitle("x");
  f1->GetYaxis()->SetTitle("y");

  // Modify colors
  f1->SetLineColor(kBlue);

  // Design
  f1->Draw();

}