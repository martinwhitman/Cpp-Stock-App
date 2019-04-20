//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <cpr/cpr.h>
#include <msclr/marshal_cppstd.h>

using namespace StockAppGUI;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}


void StockAppGUI::MainPage::GetPriceButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	// Assign api request data to r
	auto r = cpr::Get(cpr::Url{ "https://cloud.iexapis.com/beta/stock/MRK/quote/latestPrice?token=pk_05b60effc229410da18fd2dd0aa3bbae" });

	// Convert r.text from std::string to Platform::String^ and assign the value to platformString vairable
	msclr::interop::marshal_context context;
	Platform::String^ platformString = context.marshal_as<Platform::String^>(r.text);

	// Change label text
	priceOutoutLabel->Text = platformString;
}
