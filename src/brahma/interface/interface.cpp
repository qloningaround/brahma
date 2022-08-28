//
// Created by haridev on 8/28/22.
//
#include <brahma/interface/interface.h>
#include <brahma/singleton.h>

brahma::Interface::Interface() {
  utility = brahma::Singleton<brahma::InterfaceUtility>::get_instance();
}
