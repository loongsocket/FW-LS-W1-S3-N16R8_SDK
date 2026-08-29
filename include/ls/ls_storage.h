#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    bool initialized;
    uint32_t committed_writes;
    uint32_t skipped_writes;
    esp_err_t last_error;
} ls_storage_status_t;

/* NVS-backed storage. Values are committed only when their content changes. */
esp_err_t ls_storage_init(void);
esp_err_t ls_storage_get_status(ls_storage_status_t *status);

esp_err_t ls_storage_get_blob(const char *name_space, const char *key,
                              void *value, size_t *length);
esp_err_t ls_storage_set_blob(const char *name_space, const char *key,
                              const void *value, size_t length);

esp_err_t ls_storage_get_string(const char *name_space, const char *key,
                                char *value, size_t *length);
esp_err_t ls_storage_set_string(const char *name_space, const char *key,
                                const char *value);

esp_err_t ls_storage_get_u32(const char *name_space, const char *key, uint32_t *value);
esp_err_t ls_storage_set_u32(const char *name_space, const char *key, uint32_t value);

esp_err_t ls_storage_erase_key(const char *name_space, const char *key);
esp_err_t ls_storage_erase_namespace(const char *name_space);

#ifdef __cplusplus
}
#endif
