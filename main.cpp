#include <iostream>
#include <cmath> // Need this library for the pow() function

using namespace std;

int main() {
    // vars
    double faceValue;
    double couponRate;
    double marketRate;
    int years;
    int frequency;

    cout << "Bond Price Calculator" << endl;

    cout << "Enter Face Value (eg: 1000): ";
    cin >> faceValue;
    // Error checking.
    while (faceValue <= 0)
    {
        cout << "Face Value must be positive. Enter Face Value (eg: 1000): ";
        cin >> faceValue;
    }
    


    cout << "Enter Coupon Rate (in %, eg: 5.5): ";
    cin >> couponRate;
    while (couponRate < 0) {
        cout << "Coupon Rate cannot be negative. Enter Coupon Rate (in %, eg: 5.5): ";
        cin >> couponRate;
    }

    cout << "Enter Market Rate (YTM) (in %, eg: 6.0): ";
    cin >> marketRate;
    while (marketRate <= 0) {
        cout << "Market Rate must be greater than 0. Enter Market Rate / YTM (in %, eg: 6.0): ";
        cin >> marketRate;
    }


    // This is a harder part for error checking because if you enter a decimal (like 5.5) into an integer variable, C++ reads the '5' but stops at the dot, leaving '.5' stuck in the input buffer. The next command, asking for frequency, tries to read that leftover dot immediately, fails because a dot isn't an integer, and sets the frequency to 0 automatically (I think in modern C++, if cin fails, it sets the variable to 0), skipping the user's input entirely.
    // So we'll just create a temporary variable which is a double, and then check if it's an integer and then assign it to our years int. 
    double tmpYears;
    cout << "Enter years to maturity (must be ints): ";
    cin >> tmpYears;
    // Here we can use floor to check if the double is the same as the integer. 
    while (tmpYears <= 0 || tmpYears != floor(tmpYears)) {
        cout << "Years must be a positive WHOLE number (no decimals). Please re-enter: ";
        cin >> tmpYears;
    }
    // Here we are casting to int because we know that it would be an integer for sure. It would still work if we don't do this, but it's better to be explicit.
    years = (int)tmpYears;



    // Same logic here as for years.
    double tmpFreq;
    cout << "Enter frequency (1 = Annual, 2 = Semi-Annual): ";
    cin >> tmpFreq;
    while (tmpFreq <= 0 || tmpFreq != floor(tmpFreq)) {
        cout << "Frequency must be greater than 0 and an int. Enter frequency (1 = Annual, 2 = Semi-Annual): ";
        cin >> tmpFreq;
    }
    frequency = (int)tmpFreq;


    
    // Convert to decimals.
    double decimalCouponRate = couponRate / 100.0;
    double decimalMarketRate = marketRate / 100.0;

    // Adjust for frequency
    double couponPayment = (faceValue * decimalCouponRate) / frequency;
    double ratePerPeriod = decimalMarketRate / frequency;
    int totalPeriods = years * frequency;

    // Coupons PV
    double presentValCoupons = couponPayment * (1 - pow(1 + ratePerPeriod, -totalPeriods)) / ratePerPeriod;

    // Present Face val
    double presentValFaceValue = faceValue / pow(1 + ratePerPeriod, totalPeriods);

    double totalPrice = presentValCoupons + presentValFaceValue;





    
    cout << endl;
    cout << "Coupon Payment: " << couponPayment << endl;
    cout << "Total Periods: " << totalPeriods << endl;
    cout << "Bond Price: " << totalPrice << endl;

    return 0;
}