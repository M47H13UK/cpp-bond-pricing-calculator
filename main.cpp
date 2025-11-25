#include <iostream>
#include <cmath> // need this library for the pow() function

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

    cout << "Enter Coupon Rate (in %, eg: 5.5): ";
    cin >> couponRate;

    cout << "Enter Market Rate / YTM (in %, eg: 6.0): ";
    cin >> marketRate;

    cout << "Enter years to maturity (must be ints): ";
    cin >> years;

    cout << "Enter frequency (1 = Annual, 2 = Semi-Annual): ";
    cin >> frequency;

    
    // convert to decimals.
    double decimalCouponRate = couponRate / 100.0;
    double decimalMarketRate = marketRate / 100.0;

    // adjust for frequency
    double couponPayment = (faceValue * decimalCouponRate) / frequency;
    double ratePerPeriod = decimalMarketRate / frequency;
    int totalPeriods = years * frequency;

    // coupons PV
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