#if !defined(IOTYPE_H)
#define IOTYPE_H

namespace w3c {
namespace voiceinteraction {
namespace ipa {
/**
 * Type of input or output of a {@link ModalityComponent}.
 */
 */
enum IOType
{
	/**
	 * The component is an input device.
	 */
	INPUT = 0,
	/**
	 * Teh component is an output device.
	 */
	OUTPUT = 1
};

} // namespace ipa
} // namespace voiceinteraction
} // namespace w3c

#endif // !defined(IOTYPE_H)
