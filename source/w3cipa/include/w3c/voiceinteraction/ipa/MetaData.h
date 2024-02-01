///////////////////////////////////////////////////////////
//  MetaData.h
//  Implementation of the Interface MetaData
//  Created on:      13-Jun-2023 20:55:09
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_3D3A7FC2_E841_4cc6_8F89_F77CC1D02EB4__INCLUDED_)
#define EA_3D3A7FC2_E841_4cc6_8F89_F77CC1D02EB4__INCLUDED_

#include "Timestamp.h"

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
			/**
			 * Interfacce for meta data of {@llink w3c::voiceinteraction::ClientRequest}.
			 */
			class MetaData
			{

			public:
				/**
				 * Constucts a new object.
				 */
				MetaData() {
				}

				/**
				 * Destroys the object.
				 */
				virtual ~MetaData() {
				}

				/**
				 * Returns the timestamp of the request.
				 */
				virtual const Timestamp& getTimestamp() =0;
			};
		}
	}
}
#endif // !defined(EA_3D3A7FC2_E841_4cc6_8F89_F77CC1D02EB4__INCLUDED_)