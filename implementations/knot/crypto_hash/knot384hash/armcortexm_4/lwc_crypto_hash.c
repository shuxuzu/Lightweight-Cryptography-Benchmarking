#include "lwc_crypto_hash.h"
#include "api.h"


hash_ctx lwc_hash_ctx = {
	"knot384hash",
	"armcortexm_4",
	CRYPTO_BYTES,
	crypto_hash,
};

