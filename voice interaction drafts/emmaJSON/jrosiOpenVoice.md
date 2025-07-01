| features                     | JROSI       | OpenVoice                                             | EMMA                                            |
|------------------------------|-------------|-------------------------------------------------------|------------------------------------------------|
| **general**                  |             |                                                       |                                                |
| version                      | version     | version                                               | version                                        |
| schema reference             | no          | yes                                                   | yes                                            |
| utterance id                 | no          | yes                                                   | yes                                            |
| timestamps                   | no          | span                                                  | relative, absolute, start, end, duration       |
| interpretation id            | yes         | no                                                    | yes                                            |
| confidence                   | yes         | yes                                                   | yes                                            |
| alternatives                 | one-of      | interpretations are in an array                       | one-of                                         |
| tokens                       | yes         | yes                                                   | yes                                            |
| medium                       | yes         | no                                                    | yes                                            |
| mode                         | yes         | no                                                    | yes                                            |
| modalities                   | speech, text | speech, text                                         | speech, text, ink, gesture…                    |
| streaming                    | no          | planned                                               | yes                                            |
| language                     | no          | yes                                                   | yes                                            |
| mime type                    | no          | yes                                                   |                                                |
| extensibility                | info        | yes                                                   | emma:info                                      |
| location                     | no          | no, but possible through extension                    | emma:location                                  |
| **semantics**                |             |                                                       |                                                |
| intents                      | yes         | no                                                    | no, semantic format is out of scope            |
| entities                     | yes         | no                                                    | no                                             |
| entity confidence            | yes         | no                                                    | no                                             |
| intent confidence            | yes         | no                                                    | no                                             |
| alternative entities         | yes         | no                                                    | no                                             |
| alternative intents          | yes         | no                                                    | no                                             |
| model                        | no          | no                                                    | emma:model                                     |
| uninterpreted input          | no          | no                                                    | yes                                            |
| dialog                       |             |                                                       |                                                |
| speaker                      | no          | yes                                                   | yes                                            |
| dialog turn                  | no          | no                                                    | yes                                            |
| related messages/documents   | no          | no                                                    | yes                                            |   
| **system output**            |             |                                                       |                                                |
| output format                | no          | mime type                                             | emma:output-format                             |
| medium                       | no          | no                                                    | yes                                            |
| mode                         | no          | no                                                    | yes                                            |
| modalities                   | no          | speech, text                                          | speech, text, ink                              |
| streaming                    | no          | planned                                               | yes                                            |
