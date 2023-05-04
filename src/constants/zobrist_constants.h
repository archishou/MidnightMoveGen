#pragma once
#include "../types.h"
#include "../types/piece.h"
#include "../types/board_rep_types.h"

constexpr u64 ZOBRIST_PIECE_SQUARE[NPIECES][NSQUARES] = {
		{ 0xb03f6a710560ca4, 0xed3975060c14ba86, 0x27d593c487210854, 0x354213d12a653685, 0x719746ce7c9e11a1, 0xd81b188d476c1ec, 0x9755d6539624742e, 0xae9c591477522543, 0x163054c3ee901c90, 0xe417020a2fceaae0, 0xce01388387e94026, 0xf6efadaeb35fab79, 0x6b72e713795a1ea5, 0x3e43b1ee0ac3ef08, 0x604b708b2f1a388b, 0x91418f2a99de6db7, 0xc5aac196f5de021a, 0xe8c7242deec7736c, 0x4659e971c74da2f2, 0xa4294430b4394e9f, 0xb19886ce52cc7a33, 0x7c8e785e8461a3b8, 0x51f60093ccd643b4, 0x184364435dfe7124, 0x7ac5d5dad6cb1d1e, 0xb8315e0269e8b2f1, 0x858fdcc85a9ae75d, 0xa917c6f01c4d592c, 0x209339334907c0c5, 0x61ec79e911a79dbd, 0x1c1b4d0145aaa62a, 0xfd3b6865557ccf04, 0xd634731b3d65727d, 0xe703ec0e37eacf4b, 0xa7b36760c91c9b19, 0x2873f58c847aadb5, 0x3fdf3c33e5a66df1, 0x5303275757fe98bc, 0x2e2d4cdd3966564, 0x9a18303d77379612, 0x81c32eaa8ee6ce9, 0xc7cc8bbb7b72ddd6, 0x277735f53a906bdc, 0x7eff27fda480edb1, 0xc35a6b278c74708e, 0xf2573ea43c3d442d, 0xce5111564718ea6c, 0xc1d3f3d4181a8c68, 0x401ffcb80673e805, 0x30c58602cb359113, 0x62d20e1734a15920, 0xab8738ab8aa27199, 0x47ee70afb0f14d1e, 0xcb7cfd08ceaca8d2, 0x1a972359321807bd, 0xef480e9aa10007d1, 0x53a6f438449bd2ba, 0xe1e3674dbe26e551, 0x22372768f7ed554a, 0x1167b49bae3047d5, 0x8b401744c17b5247, 0xb043da8455e26d0c, 0x63ab9f5e26f7fa12, 0xd4e6e5a7a8569316, },
		{ 0x8c14c80df61984ae, 0x20900df0c5610944, 0xc648dcff7bcb5b92, 0x7b657daff8a877e9, 0x8202e7294ee2facf, 0xcd2a34e764d7f515, 0x6e33e0fc59d2573, 0x4ff70942ed0765a6, 0xde4517f673399deb, 0x10347ab44c32b95a, 0xde38323e8d7d06ab, 0xa3cd23bf912c36e, 0x94d3ae5f57e84814, 0xa62043fb10ab6190, 0xfd3c2948e9b52b8d, 0x4015e4d9d94bc044, 0x5dd26f5981963277, 0xd775c3e7b94154d, 0xa7d5aad01eab6d52, 0xd2c674797d2a09be, 0x930be917bd9173c, 0x7c45acdb3ae1061f, 0x33b93da0b9ba66ec, 0x7ded0e1d5b6b39f9, 0x9ba11f4484b0d399, 0x452c0b3fbe70a356, 0x79551f6c68696e0d, 0x6917cf75317f4aee, 0xe597319c533190b8, 0x308119154126ba47, 0x53d3fce42679e38e, 0x3066a3355a6cb4bb, 0xaf02e0646f0ff735, 0x8ed970a295f2b46e, 0xdbd4efbd64b2a4d3, 0x59595259c695b49a, 0x594137a23edcee6d, 0x1ac7667deb21e56, 0xf62d377133e4feb, 0xe6a41cdf58d73da5, 0x7ae6495b8b0a7fca, 0x12c6a5a76ba73889, 0x626f942b6334692e, 0xf469bd55266c067a, 0xc8b842715590616, 0xe57b902e0a8bfd3a, 0x16c7490fac8829c0, 0xe018d648b236ab2d, 0x9de26143f6b3a6c2, 0x54b706b99d1c5662, 0xa07d75c271c5fb51, 0xce9253d668cb5bbd, 0x6e9c94145bff2471, 0x21cd008031d45b38, 0xe4f752a4957a1d44, 0xb55ed32471e99bcf, 0x9a77660dc85befe6, 0x1421d48ab93d3223, 0x2c02392591e6fa03, 0x36b3264d72743167, 0xa8cf8fd543a12c85, 0x5a40e65a711f6ed1, 0x77a1b315dbf7d01b, 0x980e1295cddeab83, },
		{ 0xe1d47c102f741898, 0xd01ea3a2e8669aa5, 0xc53cdbdc3d2ee918, 0xb386bd1e3e6a0432, 0xf560b7d94e230317, 0xe71fc7e1cea2d5ad, 0xd8125e9a5ead2c44, 0xe5731d44835ceda2, 0x5208b918db651c2c, 0x282c09558052c15a, 0x5ab97421f73f20d2, 0x4d90affd9ad36a64, 0x447ce26f8b69b395, 0x1854fc9f93688a46, 0x679158c785dfb70e, 0xac94c76820e442da, 0x967bbd1a61bc0985, 0x919379cb173a27d2, 0x8aeacc3dd89e4de4, 0x1a344dbc51db743d, 0x40880229ef1c0330, 0xbf8c5f916b26ca8e, 0x28a43f574894073b, 0x6bd34d202d1f4a7f, 0x16ef3c35e7bcc962, 0x5187f1df1441af82, 0xe9483b7ba7d9d9aa, 0x481d5a89b4dd1acc, 0x98a19302d6e30aa, 0x469993835958e999, 0x5c907bdf50414143, 0x31c1f68ff0f55f3d, 0xdd520c59df4a2819, 0xda2ca3237e7b1087, 0xa7a4f9c0b68f1c29, 0x9bbecdf17474bda6, 0xdf32eeeac3ee4b8a, 0x87d97732c8dbb4f9, 0x5918720c830bcea9, 0xccb8a2c0eebd4d01, 0x4c39f8fab8520eea, 0x583c356021ba529c, 0x23587cca4426028d, 0x3ae857686d70a094, 0x4728659cbd66e7d4, 0x7aac3d9c02701261, 0xfff4f2d0616b699e, 0x77c8bd64d02573b5, 0x1cbec04652ff2936, 0xaa1a1931e998e4e4, 0x247ba9854d31f392, 0x3bb4c6ae5c729566, 0x3016b484c818b402, 0x2a13419416697752, 0xedf16dafb4c4ef71, 0x974f56c3304f4c76, 0x42bfc9ec8de6f22b, 0x969c98b09e752488, 0xcd1b7de1f69d5a97, 0x80b8c28a14d28be0, 0xfde0750d0b843fff, 0x6bf2e95795e4331e, 0x8a831d65c90bf545, 0xf1a432965b2d0981, },
		{ 0x5a60fc9f9d45bf5, 0x71304ab6397960f9, 0xf1e4cfce5b3b0100, 0x31503b84441ef18a, 0xb83c23d504e819b5, 0x6b6472680fa28dfe, 0x44c4c144c076d448, 0x1bdf77d1176d2998, 0x204846092758ff47, 0x3a93e17261835364, 0xba8986384d297e8c, 0x118f1588a1be9075, 0x4f85a627be03c1fa, 0xde8cbd28b96cd8cd, 0x72b127f4a3fa7189, 0xd6888becac0332e7, 0x3a86ecf11a31d092, 0xca26d87ca7789119, 0xb77021e978803238, 0xafbcad730dfef0dc, 0xdcb9a2e0546c0dc9, 0xd0781e94274af57d, 0x2dba1b54e3445390, 0xbe0a8eaf06402d40, 0x543c93f70f43d036, 0x4bed8679a143eec5, 0xb454039bcadb604, 0xccd313aaa9d71e2f, 0x122e1dd43b71e66c, 0xe7f40001c46921f, 0xfd16fb27c52daf5e, 0xeb54a71cf19a4925, 0xfc4cdfd5aa67d68a, 0x9e6cb0d9ec616b96, 0x3cc0f62b9b008e7f, 0x96934876b46ce81d, 0xa2bdc4e85cefba84, 0x1a92b13b41040a01, 0xc7175202f94ff16d, 0xe647d2ffe7bdf17c, 0x530b78d019a81332, 0xd27532aae26507b3, 0xfb3ed429135609ce, 0xb4c70e47ea378778, 0x32b84276d086d16b, 0xfb3af5a09d38a723, 0x4280778421408e3f, 0xe3abac7e62d8dca8, 0x17dd6e3bc0c81d24, 0x45fce77b8ca9bf20, 0x4f7f80b29fb1de99, 0xd2383e5331470f44, 0x6b065c1adcf43387, 0x75604233fb8ba2f2, 0xde6b370cea1c7cd2, 0x3d2b4eeea0fe1e52, 0x885dbe0e4e7c668d, 0xd3a8088bcdb489ad, 0xcbc7a18e0c2784d9, 0x4594ffccf2451f9b, 0xb01b33deb024d975, 0x5c17ab2e72d45e0, 0x5c4fe989c79822a8, 0x8d5a82b96f253542, },
		{ 0xdfab88d179a5fbd6, 0x431448ed546d6544, 0x1a4b96f06e673d2f, 0xc37fc61a2368d70f, 0x8938516c99b34e8d, 0xcdbda4f4ff0b9cb7, 0xa08fda8de44c4ee5, 0xd6fb5c57fc7324db, 0xdb894d99a2646e76, 0x258ee35e3db6de4f, 0x56b20527acf6fd31, 0xa666e0497d3bd6d1, 0x6bc1ecaacd2b78c1, 0xc4c701883b63108a, 0x841197fe5685dbf2, 0xa931bc646960a13a, 0xab19858757a40d51, 0xcdf045011561fc8, 0x6a36d52c9b3dfaf6, 0x883f88569ed5bbd, 0xfd51f30d3c8947b6, 0x5446ccb8e57c422b, 0x84673095e08bc898, 0x9602daf04e2acf91, 0x64743e9954f0ee71, 0x3235e9942f09db15, 0xdbd8a542c8e49e4c, 0x340107157bf86980, 0x6cb12d7bf273047b, 0xa4205641b3673306, 0xc8aad9ebd661873a, 0x9a2a64fb0dcdec44, 0xc884b75d78674495, 0xd5f79dfffebfc229, 0x94dbb14cf6f28c96, 0xee6c7675d426855, 0x7131dc1ff56e14b7, 0xc359a61220084209, 0x9cf9b99860827779, 0xb9ade6285d1f71f0, 0xe9eda21587079f1c, 0xc1e7a13f534a9527, 0xb3c277f5596cd98d, 0x3efc83d0045405d, 0x91a059cf029793cd, 0x1e9df3571e7c6b25, 0x399638b7bc1f35a6, 0x74156f5559cf818f, 0x709f3a623c0dac92, 0x5b83474ffdf8474b, 0x8dc7c79d5d093205, 0x57837ca03c43d291, 0x22c8a6dce618a80e, 0x545093555a948d36, 0x1b70c0d99a5d98d5, 0x3168c8ecc03b4133, 0x8ac39f7bbe901db2, 0x30ebf2aa8d5b504, 0xf89a25b0d15e89fa, 0xcd7bfd42ac621ac6, 0xed400d6d00c4a2ff, 0x38f9880b29305c3d, 0xe6f77ebc21c75ced, 0x5112d5745255be21, },
		{ 0xc5ddbf553e010dc6, 0x73d87df583b1dc83, 0x2f6b8a9becd6090d, 0x46f811582120ba76, 0xdf59ea6fda0c431b, 0xbc04a2ae80044d48, 0xb0ad9e4783354a37, 0xea4eebd90f6fa7d3, 0x734ffc346b7750e1, 0xc0074d2de22918ad, 0x73b9502cc20473c6, 0x576634d13c4c023d, 0xc1027f121aa428d2, 0x5c29220ff27b42b8, 0x69196c460e1a870d, 0xb2023b10fb1bb329, 0x6048686400161049, 0xaae160b02acc444b, 0x8b9829d1a6bff459, 0xf8841ee61847b8b, 0xda3e9830adb28f8f, 0x234661a6d850316f, 0xf894bd743dd7d949, 0xcf847fe30627b07f, 0xa065d79e79438f6f, 0x7e870507ec7c09fc, 0x4ea5ca89da2e3bc4, 0x118a42b6b21102ba, 0xc22fb3dd07408e60, 0x943c34df13884287, 0x8b7a235e74b2ae8b, 0x805ec78e1f2b55e6, 0xf2a2c2392374127f, 0xc2a6db9b58b7ad8f, 0xcd31aae73eb249ee, 0x79a993e49c9e81ce, 0xf2d99c4b09b702bc, 0x3292db3c02eb2172, 0xfa885e1a9a02f908, 0xc527947efc56696f, 0xd2a51eaa54b53878, 0xefccbb90f06fa951, 0xa4496b15776b1afe, 0x3c462edea7c1d951, 0x892aeda94ee332e7, 0x216225afeba70edd, 0x57f4093322c6ad36, 0x7f1f6c39bf05d26, 0x29fdd1fb65561c59, 0xa1b4268fb24b5763, 0x6d429da742a473a6, 0x773f6c336feecd64, 0x5e99133c2c5dc1b7, 0x4e8352d46ece2f0f, 0x82ce4eadbc71e3d9, 0xa4a8319529e40855, 0x972e6d56d2547cea, 0x9e9e759c4c5c6ee, 0x1382dfef23756a16, 0x5e7456de18aa6fd9, 0x29c57093b197f3fa, 0x5efa70a8bfe4c2af, 0x6cbe5dcf6962b815, 0x9a25feb53003b104, },
		{ 0x985e09f19b32185, 0x79fedb0bbe2027d1, 0x9dbdb8136778f47f, 0x91846e20b2ac0444, 0xbbe052b9b70b9f9c, 0x4b3f7e5d6b63ac18, 0xd271d1ef80104ed8, 0xdf2d71eb5200ffb0, 0xace82b1bd60c4437, 0x888c58366d63c7a2, 0xb4a37da09186e527, 0xcb749bbb051f8ed1, 0x811af27f2d13d014, 0x7cf08aacd0e7a0cc, 0xc9071b77694507d3, 0xde41ab41e3322cd3, 0xe813a429e980e050, 0x2b4328b00d3c210b, 0xe748b912c4b769dd, 0x6e07a72391b315dc, 0x8b1dba5dacf0008a, 0x5612e096ef8c2892, 0x572a76ae405671d6, 0x7ff09110d7e0a9b4, 0xce77cec695569b67, 0xb1913c97750448a1, 0x4f7cbb4836e8df26, 0x7beb69d8883d524f, 0xac56b60660b73fc6, 0xc48553cb5014483b, 0x35fea3e715bd2f5, 0xd49f5e2ef43068cd, 0x9a1f68dd3d4b6be9, 0x853df1bdc39bc9cb, 0x8e1d15625196cc1b, 0x9a562a35414795a6, 0x1ec6efa42da3c396, 0xd83cdcd4d16f863f, 0xd38f25dcf51b65cb, 0x2d8ea4387d339f1a, 0xaf003a62656c7c2d, 0xb3cdf22c281e5a7c, 0x68fb22f7e7233852, 0x5e1e1bb64fd32e85, 0xe6b05d2ecba26517, 0xa057bd953f88c650, 0x61037f9af6e56204, 0xbce74b4ba7a1558b, 0x413c6ff8042eccf2, 0xeb0dfb531552085d, 0xbb2f229582ca0a43, 0x3949222f928825fa, 0x5ce14eed5f883384, 0x1f1f284a9fed73ff, 0x511bb6bcee5ccf61, 0x2bd4b07332490626, 0x5ac05465123548f3, 0xad539e9e8f277396, 0x40c6388946e15630, 0x11e49a4e26478d40, 0xed7e7c761f13af21, 0xec75616ed568d6a5, 0xe54d41cf8be8aa8f, 0xe0d5310e7a2bec33, },
		{ 0x708fee35573d06da, 0x262f1538e693e02a, 0xa5790774eb111c39, 0xf137fb5ba2417f17, 0xc137ba6ef49f8620, 0xd93d053fcb738636, 0x9e441589dae7ca11, 0x1931d37401c211b8, 0x857700812827d3de, 0x2f43fea5202beade, 0xa4e659ae3c87bbbd, 0xeeabcb3e7f969d6f, 0x979665e6d7c8eeb2, 0xae71067e245ccff2, 0x4453eb11cc3e219, 0xbd8c9dd271e52598, 0x976b8dd4758ac9f1, 0xa452e0fc1d884433, 0x1fa5c182bff42a30, 0x160d639a6e998960, 0x7920ccccd0310279, 0x122c06375c0bdaab, 0x951f4d9b2a02a3e5, 0x52e1996303b3b58a, 0x15958b32096b90ba, 0xe1688953c6ab4945, 0x4fc520c00c038c6c, 0x2dbb5ba0e43f14e7, 0x477b91e8bb678a29, 0x8c2a7bd10f2da1bb, 0xbe7a62d177fb927, 0x6cf4ca5811ec27eb, 0x192cb5af94d4ab91, 0xff959647d4852a14, 0x6c3a67d4e82b96fb, 0xf7d57b35a1644a4a, 0x45c4e732680289e5, 0x618d187bb2423255, 0x61ab6a4f39b819cd, 0x1655fcec329727a4, 0x895823e7ac61073f, 0x7dbd607e70e3c1d7, 0x19f95fedfcd71a99, 0xcb79166a166459fb, 0xb5826479d9120394, 0x8b74b2f87aaccd1a, 0xe7c6936d785d2fe0, 0x56c78dd765862d5a, 0x10931fc941ee9a43, 0xa699c72ab619c53c, 0x3ce4d67fd32ada54, 0xa12a590617e810c6, 0xe739c7aeb77d0695, 0x990904d39e2d9dd1, 0x778762fa6e1cdb01, 0x75337373987e4de4, 0x2e5cd0db85e1126a, 0x4809728a2e474b09, 0xd5af7082ea94b57d, 0x2ceefc58e738b01a, 0xa185ab49d19b1429, 0xb049fd06275accc5, 0x49c8c6c3239dfa60, 0xefe30afa5d41b39d, },
		{ 0x7c8d35ea653b028c, 0xd27fcd2438b8fd70, 0x69e91c2677c1e3d2, 0xde615c95fd04e6fd, 0xea5baf5b2554b353, 0xe865552c46769bef, 0x3574c8fe4e7044e0, 0xf2c67c732e1b3ac9, 0x36de14e8a5a0646c, 0x5b51a5d8d36a010a, 0xf953f7fd65098d7b, 0xfff35c5bfe094cb9, 0xa2e3fdfe73f7f92b, 0x67a4849cb1426f73, 0x1ad46d0d53d01b74, 0xa14219a8928b8be6, 0xee4d983985fa2032, 0xad96d3c3cd2e91b5, 0x8605499b92f440c0, 0x4f9dbb14bb585366, 0x444ae2298aafff19, 0xea8e472ee1b879f4, 0x1518b2636d9f1663, 0x8eebd5bcf6aa2fb5, 0x16ae679ac8ab0ea1, 0x826060451d423adc, 0x4e0db5d3ff9cf24e, 0xee477f4ed4ea9c34, 0xfb1f88d17c584202, 0x4fb01ef24ad9341d, 0x2d19eb0b4e8ba64e, 0x487562af34c306a1, 0x7fc9240f26fede15, 0x178162d2838ca36a, 0x2992a49d63a99ca7, 0x58d91e324ef3d036, 0x3f06df8f13e0660f, 0x999aef3f89f06fb9, 0x83c1c1c97a08a755, 0xa2244a72b9c8a, 0x82740bf5748d3a1, 0xe7cb861472a3a05, 0x3616b9bfcc5bad3a, 0xde5093191a5a7081, 0x67cfa38907e41013, 0x54754fd2f5eee2c9, 0x9474a3a46404a4f4, 0x53770f3c4bd19c58, 0x1bece7e7eef4d807, 0x9706dfbf68443dc1, 0xa1996c4666847e3c, 0x36cf6ff59b11c931, 0xf62bd07a29258fb8, 0x1a69e33d1f187d3e, 0xbce859dfbf59c0fd, 0xe018fc51764fb8c9, 0xf3c9ccf79d812ba, 0xa9c9bc6f0e539957, 0xec67987c9c5266c8, 0xb06ec0bb084bdb2c, 0xcdc3976cecbeb44f, 0x9f67d3a374512d67, 0x56f19a17568958c8, 0xbf010c645d014797, },
		{ 0xf49414eacfe0141a, 0xbd51eca5ea37f165, 0x5a7692329da41afa, 0x2f0d87b33ed5f153, 0xfa4972b3390f4df8, 0x93b3e130ca8bc4e8, 0x458e02565fcc17de, 0x235cdeeaeb4993fb, 0xba7acd78654a07c3, 0x16aeb28d321983be, 0x2607c70efbd9be9a, 0x974a01b53f0ab949, 0x476eabb1464375a8, 0x4a2dddfb8d4827b9, 0xafbc95874516756b, 0x65cdfccb65ba0f19, 0xf757b4c42e13788, 0xd9218865a56e5871, 0x15f5ed4a2001ad6b, 0x47739a5980dc5eab, 0x6814bd661394deb, 0x80f41377d8430b23, 0x44b223fbe854a328, 0x4b69d41b5e9f870, 0xc6d9b53e3e84788a, 0x5f542ee82825052, 0x44843edc1e4a802f, 0x15a905f67cb55342, 0x1623a310395ced83, 0xe87e92c5fdcb76c3, 0x178b88ce32235df9, 0xe17bfab0edbb9997, 0xd16a2ef81613ba4d, 0xfe0e2a26ffe70ede, 0x58321bb2ebb4f9a1, 0xbac1bb62b996296e, 0x80d2068973391e5f, 0x5371f5afca3ad0d5, 0x47ffc81a87e2a11b, 0xa7ff95b953e0be6d, 0x325b715b86c40621, 0xca4874dcae30cfde, 0x448a4217ea35762, 0xef96f9a82964272a, 0xff1a20f4ce0df576, 0xafb2a8e824511402, 0x990a901ea0beeaff, 0x6fb505dd89af8788, 0xfcfe7d3acfa8ad5, 0x73e5ff12a3e251c2, 0xb2a435324e459a22, 0x84da675fb3cff5c, 0xfdbbb57504cd6f2e, 0xc4826d505a36e1ca, 0xf405fab48b4d561a, 0x55422375bf241958, 0x4d95690146d2bc34, 0x795018fc54dd05cc, 0x983ff9ab2e31c1e7, 0xed7fd97abec953cb, 0x5b3c6c3215ce1877, 0x63bc327010c5a593, 0x354c08d04590a008, 0x4828ecc848061395, },
		{ 0x8e033b03966ac833, 0xb17fc47e477444e6, 0xbfed64641e6f9bed, 0xf8730345fd3f0ec6, 0x1506f7250d4369ab, 0xc6bb9058e134f1b0, 0xc5f453f715f1b5a0, 0xd55991085b036dd9, 0x3b72873ed27b95a4, 0x7a0c53e23661a1c8, 0x78dfc8a5cab509b3, 0xf83e5c0a0573915e, 0xd687c6460b653460, 0xe0ebff8ab21bab5f, 0x4a285ce94e03a59e, 0x4979dc209e5d053c, 0x8767987f06ecad79, 0x75c7935bc65197c, 0xe7faffdb5396b00d, 0x3f93bb2a4a322943, 0x6e6715d272f7585b, 0xeb1bc0151c9b6644, 0x1c631d95e7a1dd2b, 0xee15b5848080f201, 0xd7fcee69bf278fb, 0x45d5e99e513a8e7d, 0x3ded716c660625c1, 0xadd1574140df0ab5, 0xef575030cb1cbe52, 0xfa274ca6557e0c85, 0x87d8f2ef062bb242, 0xecc8b5ef0320d4f7, 0xaadd3f82f181d605, 0x8090810ce247d761, 0x8f3893f0482a771e, 0x9280fd02187285c2, 0x99dddc48aeb67c8d, 0x98dea536c71fc319, 0x9d6b2a37e912aced, 0x7a8b49d3fdbf767e, 0x1d531630daee75a7, 0xcfbbcf9579b45443, 0x97d2e7e212ba83b4, 0x6be6f5e40b0d2471, 0xa5c3f8f56a2ff928, 0x556f02765db5d75a, 0x8a016e8f59923a26, 0x66494d0f6a66d242, 0xcefcf09b80950834, 0x93d78a5d3e949682, 0x73040c64d33e5874, 0xe4bdd8e851a95b89, 0xfa144738146405b6, 0x28704783a8dae845, 0xf960331788dfdada, 0xd43ac58991469198, 0x3e97031d5fc1650d, 0x8a2e234c5969043f, 0x28c58847b91193f9, 0x4763a3865cd32d07, 0xfe9a6aa213daf553, 0xce857e6d712dcf51, 0x4f9f6dbb1a6571d1, 0x1771e1ca7e572fd3, },
		{ 0x272f082368938347, 0x8791b73ae37f81ac, 0xcd617856de561865, 0xed3ec9e0b4debf12, 0x8cc4bb6a1b94d240, 0xe963b571b64d70b5, 0xeed80b6ed7cb9dee, 0x498cc22c22e3755d, 0x7002a2db8ad20858, 0xe14754611e49977d, 0xd91f0a6ceb67c612, 0x389c878dc99ac755, 0x6d474c106eea58ac, 0x44a3b2a720f7c700, 0x848586f6768e9fd3, 0x8a93e1e37b0cd88c, 0xbb474e32fb19716c, 0x5aef286083cb0b40, 0x93db71a63c1ea19d, 0x56b22048640d1dae, 0xca1be64422c38ac2, 0x6623d75caf443b41, 0x38079e0c6956c10d, 0x328ac89bc47e3f68, 0xa9a666b255cf73f8, 0xdfc35fef0c059ff8, 0x49adb7ae0a4b451c, 0x9aa621b31e4e8f93, 0xbb00c0935471e58e, 0x8378f22b10059c2a, 0x28803786db345350, 0xc0bbfb3005b2f7db, 0xd7936166d74e453d, 0x1eb909a8f891307f, 0xbc68e3a2ae0636ae, 0x7a0d812f788517fd, 0x71d4df0d2a661e21, 0x7db46fc4677c3a3d, 0x60d9da0401af51bf, 0x91174e53987e21a1, 0x7ae552da602d96f3, 0x5bce4d6d377a85ee, 0xa38c1f660effe103, 0xa3434424c3c47a0, 0xcc1d2e570215fb7e, 0xf628a67b95ec663b, 0xa88e5c0a12b9d02e, 0xb3e0742152084374, 0xa2696c8fe996c9fd, 0x8c3d08e8e0836ffb, 0xa7608c316215ad8b, 0xd0ec57ed959db05a, 0x77b5e30e8638587c, 0x5091b9b4841cd7d6, 0x3744e23adcbaa54e, 0xa4688281ba1c268b, 0xab332c6eb6a3e0ba, 0x94b161d5fb21dcaf, 0x94c3c0e33925b931, 0xc86d0700b7a37491, 0x20156e56257e489d, 0xc25d4d4ea5036e40, 0xcea86bc417e69eb, 0xd9890895a353f558, },
		{ 0x4600ca890e39b338, 0xe20a2861897baa29, 0x892057743af6581e, 0x79c9c16d26f41da3, 0x303f1fa01df8c96e, 0x4b2b9d8cfbcd6e90, 0x454a99af8cb9537e, 0x6c0c571edf358b6f, 0x4231658c78110198, 0xfb4af6c1b004199a, 0x4f88b67ec9d78f10, 0x8440dbe42a2a840, 0x96c948a8e8bb86b1, 0x75d339ba46a2e1e7, 0x4648428ce88875cf, 0x15602960d8ab6f6d, 0x1aecd8b2d5bd44f, 0xa7a31a7b1dca85fc, 0xc281c8936f137f11, 0xcdc74643230f501a, 0x46e61a3fddccf5f5, 0x7439dc8762178e27, 0x71956fb3fecd7828, 0x60c37bc724759878, 0xa6199423b215f03e, 0xbe7c90c32ac3d85d, 0x4e739145a465ba0d, 0x5697c4a51f2835fb, 0xa119809125b91184, 0x3725b2cab89e149a, 0x7b7ecdec85392207, 0x88d1eb900087b996, 0x7dfddb3f204f8f6b, 0x816d4c6829ac22e3, 0xd8941c571c759fcf, 0xacf8d003c31d9a48, 0x580fc7e877fe398b, 0x1decfb5e8b27f0e3, 0x296bb72666dcf5ca, 0xeb92a4d0a6f40398, 0xb925bb8013d8e2cb, 0x9842e298157c92d0, 0x8d4adbf152302e3, 0xc2550242342d189f, 0xdca5582004ba4d73, 0xf003d546de8acfaa, 0x9c238423469a7955, 0xd93618f591a8df69, 0x466fcba4acb78ed5, 0x53cd8cf1e3c3d9b5, 0xdb18ff96e5933c6e, 0xbb9a0a3731c168bf, 0xdc113c2da8faa04e, 0x35800a8a30097db, 0xf4d7b57d05e58425, 0x6cf985ed6a0a7d02, 0x3bd4b90f26ddf04b, 0xe8a89d366bed1604, 0xab0849bd2633a834, 0xd8b82fb0388912c8, 0x5846698ceae1b318, 0x3d2494bceddbbec3, 0x987de44bc67c032c, 0x4c6ae1c15745dfb3, },
		{ 0x2b4a0d99924f167d, 0x96eed71797a7bad3, 0xfec0d2d065b509dc, 0xaadf733ca5845223, 0xe2d7d7038fc52714, 0x44586874811e2bfc, 0x1c6520c32d050224, 0x3ea62a00e8d38477, 0x3e0f5ce23ac1101, 0xebf809b753bf249c, 0x65247be6f0610bdc, 0x9a1014b017270d87, 0x2ce66baded768af5, 0x3d34c11622c880f6, 0x5ff22bb92dd50f16, 0xf6201da4b9a2604e, 0x44569ad2f9d64db2, 0xebdfc59238df93e, 0xb07c9e708434d24, 0x53d26bd38c9b28af, 0x4fbcf7a03848ed6a, 0xe731a2c7f592f2af, 0x4ec930ff112bcb28, 0xca10bb2a7cb3e351, 0xb96183e36841ceb3, 0xe8f763ac723214ae, 0xbee8a3de68c02f1, 0x2d7eede8267040b5, 0xe4d47a85dbbfb69a, 0xc4186e3cc244edc2, 0xc95e67824d4f2610, 0xba315a14a666951b, 0xf64f25d592545543, 0xd32560d08cd80704, 0xc40cbb1afc619ce5, 0x198b86bfd6af4702, 0x9bc19ce0b31e541f, 0xcf6316da906a56ed, 0x45066aec95a1a6b1, 0x7abb8c63cb04d508, 0x1fd1fa5a082e3c8d, 0x19761349a4309744, 0x3bb6a025176c3139, 0x1708ffd4a3d35077, 0x97c23ca0521b42d7, 0x2ae855c93166dada, 0x6bceb341895ffb4d, 0xf2e18458e33ce813, 0x38d413ab85e3d4fa, 0xc069b1825592687d, 0x94d57793180a88ad, 0x34fb11c184d954fa, 0x4b4cd48a4a9ea21c, 0xfe0f283eaecef120, 0x1bda5f527943d38d, 0x83419a710054cf8f, 0x1b138d7adfac774c, 0xd434b8437c5d86e0, 0x1572427cd58116ba, 0x89bf3bf09247ba27, 0xe1d5d808b2ce13dc, 0x16b60ff40961ade8, 0x3d1ad518138e688e, 0xbcb1559614a45fe8, },
		{ 0xb463fb4253e6087b, 0x85cd5e060ecd1786, 0x21f35a35e289a5d3, 0x912d826d6bbafc2b, 0xb38bf976b9c26b0c, 0x964db517ef2a1476, 0x3e7033cf06429b46, 0xb71ed67db3095985, 0xaec26d210fda4160, 0xf6e51c3404e4e758, 0xea37bb6c51ef803b, 0xcfb70678bd794e5, 0x507c891b07501e44, 0xb095f43071712b32, 0xf099ef63d7a80858, 0xb7f809ef0f5e6073, 0xd58ebdb3c19d3f07, 0x8fb490a439530c7, 0x598839f37f5d9a59, 0xc8ef56f0d99cd604, 0x78b3ae9f183f2cce, 0xd418821cd6d0df03, 0x7950e85348504fe9, 0xac11f1e9ebae24d2, 0x1120df6c9194216f, 0xfd7165163597cd0b, 0x13a45381a073f944, 0xd4e62404170841e6, 0xe9d22c5fd4a647f, 0x5116347a9f81e22, 0x9b99e9110610423, 0xb30f3bcb52a98c37, 0x604fc0542a2fdc32, 0xe6cc61a80d714d1e, 0x31e78bf0626a8c40, 0x672c713b45c99df6, 0x5dd41a47c033c2ed, 0xa3444a2e60b7e6da, 0xb7b849b7f6589fd0, 0xfe25a713bb649d22, 0xe54119581fce4679, 0x4a2808ee0c9dd2a7, 0x5b3a23ebb892b921, 0x1d109708b713a320, 0xe9c304cdc8b7cf18, 0x95be961919ec17de, 0x7f766b667d4b41e6, 0x67b9e4c861781157, 0x2d1893dad92ce12, 0x8e007c606e516209, 0xe963548821c23893, 0x51e7a5499dcc514f, 0x4920fa023bbb3f44, 0xc867cbc92ee1e2fa, 0xf66b481318cb083, 0xc6a74ed599bc1a7, 0xc97d66687819388d, 0xda92d340d2ff3f5f, 0xca20a6162643045d, 0x1cd64b6e1d2d2ac8, 0xa51a0b0965608ce2, 0xe8a80a35f4a76155, 0x688592ea54556d0c, 0x165bc54a808ccc23, },
};

constexpr u64 ZOBRIST_CASTLING_RIGHTS[NCASTLING_RIGHTS * NCASTLING_RIGHTS] = {
		0x27a6232b09e17a7c, 0x446ec80dd510973, 0xc714579ab1aa53e0, 0x169cc5508ae0ac1b,
		0xf05aeca1e54c3c8e, 0xbb0c11bd2c9152e7, 0x9a43e5c630ff989a, 0xd2d00416fe8e7c37,
		0xd306d760f5457c26, 0x53196a88ebded707, 0x38c7b1e83ec50f39, 0xdc089734a7f12b07,
		0xc1b5e792f0ff738b, 0x4b4c7e6a10d96839, 0x4aca9be5bcf07993, 0x85540db6f23f66f2,
};

// NSQUARES + 1 for no ep square.
constexpr u64 ZOBRIST_EP_SQUARE[NSQUARES + 1] = {
		0x6a83bc36f0495ef4, 0xc85f640b09faf6ab, 0x6147944e9b24699d, 0x6291014eeab4c810, 0x385e9ce5bad2aa07, 0x9289dd2f3b369ac, 0xffc65340107e5d5, 0x8a27e0fd0a838aad,
		0xdc2544201e621658, 0xb00daea48e827644, 0xd92ddac513d63745, 0x6065868b8679daf9, 0x55b2dfb01c995ebd, 0x4cf075e6b943a18, 0x23bb15b9907bb3d7, 0x2168b7ccb834744c,
		0x9a57b96a6b7a7e55, 0xea71efae40d96a26, 0xd1cb1ba6537ec782, 0xc259a753f4f4fef4, 0x17e9af670c158ee3, 0xabad004cd9dfc2e1, 0xd4a373084b08f146, 0x5609f6df88be155c,
		0x85580595488cd7bb, 0xf027b3e84bcaf972, 0xe0ed76e236aa49f4, 0x81025b98ee8a206c, 0xec9fbebc926d9588, 0xc5dd03ccc6b2420b, 0x66d7200d9e9cf62d, 0x7421b83194233d2a,
		0x37fb96fff362370, 0xbe90de574440c594, 0xd75cab6b9892862f, 0x3c27926b182d2c6d, 0x139d5e59bdd6e548, 0x840daad34fbd20e3, 0x81232d93327fbdc1, 0xb31beca25e05068c,
		0xf5baf2cef1d12b2b, 0x8c0866f295dfbebd, 0xbeaea688a8168559, 0xfff3784ab68dfe0, 0x63ddf8e753c95933, 0xb39e1e6e3b68f89c, 0xf9e230b290e70a38, 0xf05c05fe9bab000b,
		0xd41d68cd1f789e21, 0xe39eb9e76b90810c, 0xf628ceb34f8aa125, 0x92c71291b5ce8350, 0x29fcec256d7203a, 0x7cfd4d800b133e5, 0x63d994163c375b63, 0xf2a2452977c6ed20,
		0x580a92cdae7327d8, 0x2b2265f5f534e9b8, 0x1bfc55cf26a7baab, 0x39634286cc2534ce, 0xaaf196335586d1c9, 0x261b66fbdbfbd7e1, 0x68f248327514d19e, 0x9e6a49c027a27b3,
		0x1026375f03408983,
};

constexpr u64 ZOBRIST_COLOR[NCOLORS]= {0x750ee814dc0e551c, 0x1026375f03408983};