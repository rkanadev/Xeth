#pragma once

#include "detail/AddressValidator.hpp"
#include "detail/Sender.hpp"
#include "detail/GenericSendCommand.hpp"

namespace Xeth{


typedef GenericSendCommand<AddressSender, HexAddressValidator> SendToAddressCommand;



}