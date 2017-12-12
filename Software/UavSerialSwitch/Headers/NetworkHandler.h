#ifndef HEADERS_NETWORKHANDLER_H_
#define HEADERS_NETWORKHANDLER_H_

#include "SpiHandler.h"
#include "PackageHandler.h"
#include "FRTOS.h"

/*! \def QUEUE_NUM_OF_WL_PACK_TO_SEND
*  \brief Number of wireless packages that should have find space within a single queue.
*/
#define QUEUE_NUM_OF_WL_PACK_TO_SEND			10 /* about 550 bytes per wireless package, not including the dynamically allocated memory for payload */

/*! \def MAX_NUMBER_OF_UNACK_PACKS_STORED
*  \brief Size of internal array for unacknowledged packages.
*/
#define MAX_NUMBER_OF_UNACK_PACKS_STORED		100

/*!
* \fn void networkHandler_TaskEntry(void)
* \brief Task generates packages from received bytes (received on device side) and sends those down to
* the packageHandler for transmission.
* When acknowledges are configured, resending is handled here.
*/
void networkHandler_TaskEntry(void* p);

/*!
* \fn void networkHandler_TaskInit(void)
* \brief Initializes all queues that are declared within network handler
* and generates random session number
*/
void networkHandler_TaskInit(void);

/*!
* \fn uint16_t numberOfPackagesReadyToSend(tUartNr uartNr)
* \brief Returns the number of packages stored in the queue that are ready to be sent via Wireless
* \param uartNr: UART number the package should be transmitted to.
* \return Number of packages waiting to be sent out
*/
uint16_t numberOfPackagesReadyToSend(tUartNr uartNr);

/*!
* \fn ByseType_t popReadyToSendPackFromQueue(tUartNr uartNr, tWirelessPackage *pPackage)
* \brief Stores a single byte from the selected queue in pData.
* \param uartNr: UART number the package should be transmitted to.
* \param pPackage: The location where the package should be stored
* \return Status if xQueueReceive has been successful, NULL if uartNr was invalid
*/
BaseType_t popReadyToSendPackFromQueue(tUartNr uartNr, tWirelessPackage *pPackage);


#endif
