﻿#pragma once
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------


namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                ref class Canvas;
                ref class Button;
                ref class TextBox;
                ref class TextBlock;
            }
        }
    }
}

namespace StockAppGUI
{
    [::Windows::Foundation::Metadata::WebHostHidden]
    partial ref class MainPage : public ::Windows::UI::Xaml::Controls::Page, 
        public ::Windows::UI::Xaml::Markup::IComponentConnector,
        public ::Windows::UI::Xaml::Markup::IComponentConnector2
    {
    public:
        void InitializeComponent();
        virtual void Connect(int connectionId, ::Platform::Object^ target);
        virtual ::Windows::UI::Xaml::Markup::IComponentConnector^ GetBindingConnector(int connectionId, ::Platform::Object^ target);
    
    private:
        bool _contentLoaded;
    
    
        private: ::Windows::UI::Xaml::Controls::Canvas^ MainCanvas;
        private: ::Windows::UI::Xaml::Controls::Canvas^ Controls;
        private: ::Windows::UI::Xaml::Controls::Canvas^ Labels;
        private: ::Windows::UI::Xaml::Controls::Canvas^ InputFields;
        private: ::Windows::UI::Xaml::Controls::Canvas^ Buttons;
        private: ::Windows::UI::Xaml::Controls::Button^ getPriceButton;
        private: ::Windows::UI::Xaml::Controls::Button^ exitButton;
        private: ::Windows::UI::Xaml::Controls::TextBox^ tickerBox;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ tickerLabel;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ priceLabel;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ priceOutoutLabel;
    };
}
