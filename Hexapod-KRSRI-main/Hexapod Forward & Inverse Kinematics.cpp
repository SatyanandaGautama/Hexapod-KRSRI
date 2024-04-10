#include <iostream>
#include <cmath>
// Function declaration
void forwardKinematik(float theta_c, float theta_f, float theta_t);
void inversKinematik(float x, float y, float h);
// Global variables (for demonstration purposes)
const int cx = 22;  // Adjust if needed
const int fm = 58;  // Adjust if needed
const int tb = 80;  // Adjust if needed
int height = -100;
float z, sdtcoxa, sdtfemur, sdttibia, theta2, theta3, angle1, angle2, P, c, alas, alpha, beta;
const int legoffset[6] = {0, 45, 135, 180, 225, 315};

int main() {
  inversKinematik(55, 55, 0);
  forwardKinematik(45, -20, 21);
  return 0;
}

void forwardKinematik(float theta_c, float theta_f, float theta_t) {
  theta_f = theta_f * M_PI/180;
  theta_t = theta_t * M_PI/180;
  theta_c = theta_c * M_PI/180;
  float p = cx + fm*cos(theta_f) + tb*sin(theta_f + theta_t);
  float x = p * cos(theta_c);
  float y = p * sin(theta_c);
  float alas = p - cx;
  float beta = acos((fm * fm + cx * cx - tb * tb) / (2 * fm * cx));
  float alpha = theta_f - beta;
  float z = (tan(alpha) * alas) - 80;
  std::cout << "x : " << round(x) << std::endl;
  std::cout << "y : " << round(y) << std::endl;
  std::cout << "z : " << round(z) << std::endl;
}

void inversKinematik(float x, float y, float h) {
  angle1 = round ((atan(y / x) * 180 / M_PI));
  sdtcoxa = (round(angle1));
  z = height + h;
  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = round((theta2 * 180 / M_PI));
  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = round((theta3 * 180 / M_PI) - 90);
  std::cout << "Sudut Coxa : " << sdtcoxa << std::endl;
  std::cout << "Sudut Femur : " << sdtfemur << std::endl;
  std::cout << "Sudur Tibia : " << sdttibia << std::endl;
  //  Serial.println("FRONT RIGHT :");
  //  Serial.print("CX :");
  //  Serial.println(sdtcoxa);
  //  Serial.print("FM :");
  //  Serial.println(sdtfemur);
  //  Serial.print("TB :");
  //  Serial.println(sdttibia);
}
