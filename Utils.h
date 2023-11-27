/*******************************************************************************
 * Utility related function
 *
 ******************************************************************************/

void debugJpeg(
    const char *filename, bool useBigEndian,
    int x, int y, int _x, int _y, int widthLimit, int heightLimit,
    int _scale, int iMaxMCUs, float ratio) {
    Serial.print("== filename: ");
    Serial.println(filename);
    Serial.print("== *filename: ");
    Serial.println(*filename);
    Serial.print("== useBigEndian: ");
    Serial.println(useBigEndian);
    Serial.print("== x: ");
    Serial.println(x);
    Serial.print("== y: ");
    Serial.println(y);
    Serial.print("== _x: ");
    Serial.println(_x);
    Serial.print("== _y: ");
    Serial.println(_y);
    Serial.print("== _x_bound: ");
    Serial.println(_x_bound);
    Serial.print("== _y_bound: ");
    Serial.println(_y_bound);
    Serial.print("== widthLimit: ");
    Serial.println(widthLimit);
    Serial.print("== heightLimit: ");
    Serial.println(heightLimit);
    Serial.print("== _scale: ");
    Serial.println(_scale);
    Serial.print("== ratio: ");
    Serial.println(ratio);
    Serial.print("== iMaxMCUs: ");
    Serial.println(iMaxMCUs);
}


void debugPinOuts(
  Serial.print("MOSI: ");
  Serial.println(MOSI);
  Serial.print("MISO: ");
  Serial.println(MISO);
  Serial.print("SCK: ");
  Serial.println(SCK);
  Serial.print("SS: ");
  Serial.println(SS);
}

#endif // _UTILS_H_
