# LS Storage API

Header: `components/ls_storage/include/ls_storage.h`

The storage component wraps NVS and only commits values when their content
changes. This reduces unnecessary flash writes.

## Main Types

`ls_storage_status_t`

- `initialized`
- `committed_writes`
- `skipped_writes`
- `last_error`

## Functions

```c
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

esp_err_t ls_storage_get_u32(const char *name_space, const char *key,
                             uint32_t *value);
esp_err_t ls_storage_set_u32(const char *name_space, const char *key,
                             uint32_t value);

esp_err_t ls_storage_erase_key(const char *name_space, const char *key);
esp_err_t ls_storage_erase_namespace(const char *name_space);
```

## Notes

- Use short namespaces and keys.
- Use `ls_storage_get_status()` during endurance tests to see committed and
  skipped writes.
