///////////////////////////////////////////////////////////
//  SessionId.h
//  Implementation of the Interface SessionId
//  Created on:      13-Jun-2023 20:55:10
//  Original author: Dirk Schnelle-Walka
///////////////////////////////////////////////////////////

#if !defined(EA_5D623C18_968C_4465_A5F1_DB5D928347E0__INCLUDED_)
#define EA_5D623C18_968C_4465_A5F1_DB5D928347E0__INCLUDED_

namespace w3c
{
	namespace voiceinteraction
	{
		namespace ipa
		{
			/**
			 * The SessionId interface is used to identify a session.
			 */
			class SessionId
			{
			public:
				/**
                 * Constucts a new SessionId.
                 */
				SessionId() {
				}

				/**
				 * Destroys the SessionId.
				 */
				virtual ~SessionId() {
				}

			};

		}

	}

}
#endif // !defined(EA_5D623C18_968C_4465_A5F1_DB5D928347E0__INCLUDED_)
