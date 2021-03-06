#ifndef __LIBCLI_SMB2_SMB2_PROTO_H__
#define __LIBCLI_SMB2_SMB2_PROTO_H__

#undef _PRINTF_ATTRIBUTE
#define _PRINTF_ATTRIBUTE(a1, a2) PRINTF_ATTRIBUTE(a1, a2)
/* This file was automatically generated by mkproto.pl. DO NOT EDIT */

#ifndef _PUBLIC_
#define _PUBLIC_
#endif


/* The following definitions come from libcli/smb2/transport.c  */

struct smb2_transport *smb2_transport_init(struct smbcli_socket *sock,
					   TALLOC_CTX *parent_ctx);
void smb2_transport_dead(struct smb2_transport *transport, NTSTATUS status);
void smb2_transport_send(struct smb2_request *req);
void smb2_transport_idle_handler(struct smb2_transport *transport, 
				 void (*idle_func)(struct smb2_transport *, void *),
				 uint64_t period,
				 void *private);

/* The following definitions come from libcli/smb2/request.c  */

struct smb2_request *smb2_request_init(struct smb2_transport *transport, uint16_t opcode,
				       uint16_t body_fixed_size, BOOL body_dynamic_present,
				       uint32_t body_dynamic_size);
struct smb2_request *smb2_request_init_tree(struct smb2_tree *tree, uint16_t opcode,
					    uint16_t body_fixed_size, BOOL body_dynamic_present,
					    uint32_t body_dynamic_size);
NTSTATUS smb2_request_destroy(struct smb2_request *req);
BOOL smb2_request_receive(struct smb2_request *req);
BOOL smb2_request_is_error(struct smb2_request *req);
BOOL smb2_request_is_ok(struct smb2_request *req);
BOOL smb2_oob(struct smb2_request_buffer *buf, const uint8_t *ptr, size_t size);
size_t smb2_padding_size(uint32_t offset, size_t n);
NTSTATUS smb2_pull_o16s16_blob(struct smb2_request_buffer *buf, TALLOC_CTX *mem_ctx, uint8_t *ptr, DATA_BLOB *blob);
NTSTATUS smb2_push_o16s16_blob(struct smb2_request_buffer *buf, 
			       uint16_t ofs, DATA_BLOB blob);
NTSTATUS smb2_push_o16s32_blob(struct smb2_request_buffer *buf, 
			       uint16_t ofs, DATA_BLOB blob);
NTSTATUS smb2_push_o32s32_blob(struct smb2_request_buffer *buf, 
			       uint32_t ofs, DATA_BLOB blob);
NTSTATUS smb2_push_s32o32_blob(struct smb2_request_buffer *buf, 
			       uint32_t ofs, DATA_BLOB blob);
NTSTATUS smb2_pull_o16s32_blob(struct smb2_request_buffer *buf, TALLOC_CTX *mem_ctx, uint8_t *ptr, DATA_BLOB *blob);
NTSTATUS smb2_pull_o32s32_blob(struct smb2_request_buffer *buf, TALLOC_CTX *mem_ctx, uint8_t *ptr, DATA_BLOB *blob);
NTSTATUS smb2_pull_s32o32_blob(struct smb2_request_buffer *buf, TALLOC_CTX *mem_ctx, uint8_t *ptr, DATA_BLOB *blob);
NTSTATUS smb2_pull_o16s16_string(struct smb2_request_buffer *buf, TALLOC_CTX *mem_ctx,
				 uint8_t *ptr, const char **str);
NTSTATUS smb2_push_o16s16_string(struct smb2_request_buffer *buf,
				 uint16_t ofs, const char *str);
void smb2_push_handle(uint8_t *data, struct smb2_handle *h);
void smb2_pull_handle(uint8_t *ptr, struct smb2_handle *h);

/* The following definitions come from libcli/smb2/negprot.c  */

struct smb2_request *smb2_negprot_send(struct smb2_transport *transport, 
				       struct smb2_negprot *io);
NTSTATUS smb2_negprot_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx, 
			   struct smb2_negprot *io);
NTSTATUS smb2_negprot(struct smb2_transport *transport, 
		      TALLOC_CTX *mem_ctx, struct smb2_negprot *io);

/* The following definitions come from libcli/smb2/session.c  */

struct smb2_session *smb2_session_init(struct smb2_transport *transport,
				       TALLOC_CTX *parent_ctx, BOOL primary);
struct smb2_request *smb2_session_setup_send(struct smb2_session *session, 
					     struct smb2_session_setup *io);
NTSTATUS smb2_session_setup_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx, 
				 struct smb2_session_setup *io);
NTSTATUS smb2_session_setup(struct smb2_session *session, 
			    TALLOC_CTX *mem_ctx, struct smb2_session_setup *io);
struct composite_context *smb2_session_setup_spnego_send(struct smb2_session *session, 
							 struct cli_credentials *credentials);
NTSTATUS smb2_session_setup_spnego_recv(struct composite_context *c);
NTSTATUS smb2_session_setup_spnego(struct smb2_session *session, 
				   struct cli_credentials *credentials);

/* The following definitions come from libcli/smb2/tcon.c  */

struct smb2_tree *smb2_tree_init(struct smb2_session *session,
				 TALLOC_CTX *parent_ctx, BOOL primary);
struct smb2_request *smb2_tree_connect_send(struct smb2_tree *tree, 
					    struct smb2_tree_connect *io);
NTSTATUS smb2_tree_connect_recv(struct smb2_request *req, struct smb2_tree_connect *io);
NTSTATUS smb2_tree_connect(struct smb2_tree *tree, struct smb2_tree_connect *io);

/* The following definitions come from libcli/smb2/create.c  */

struct smb2_request *smb2_create_send(struct smb2_tree *tree, struct smb2_create *io);
NTSTATUS smb2_create_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx, struct smb2_create *io);
NTSTATUS smb2_create(struct smb2_tree *tree, TALLOC_CTX *mem_ctx, struct smb2_create *io);

/* The following definitions come from libcli/smb2/close.c  */

struct smb2_request *smb2_close_send(struct smb2_tree *tree, struct smb2_close *io);
NTSTATUS smb2_close_recv(struct smb2_request *req, struct smb2_close *io);
NTSTATUS smb2_close(struct smb2_tree *tree, struct smb2_close *io);

/* The following definitions come from libcli/smb2/connect.c  */

struct composite_context *smb2_connect_send(TALLOC_CTX *mem_ctx,
					    const char *host,
					    const char *share,
					    struct cli_credentials *credentials,
					    struct event_context *ev);
NTSTATUS smb2_connect_recv(struct composite_context *c, TALLOC_CTX *mem_ctx,
			   struct smb2_tree **tree);
NTSTATUS smb2_connect(TALLOC_CTX *mem_ctx, 
		      const char *host, const char *share,
		      struct cli_credentials *credentials,
		      struct smb2_tree **tree,
		      struct event_context *ev);

/* The following definitions come from libcli/smb2/getinfo.c  */

struct smb2_request *smb2_getinfo_send(struct smb2_tree *tree, struct smb2_getinfo *io);
NTSTATUS smb2_getinfo_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx,
			   struct smb2_getinfo *io);
NTSTATUS smb2_getinfo(struct smb2_tree *tree, TALLOC_CTX *mem_ctx,
		      struct smb2_getinfo *io);
uint16_t smb2_getinfo_map_level(uint16_t level, uint8_t class);
struct smb2_request *smb2_getinfo_file_send(struct smb2_tree *tree, union smb_fileinfo *io);
NTSTATUS smb2_getinfo_file_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx,
				union smb_fileinfo *io);
NTSTATUS smb2_getinfo_file(struct smb2_tree *tree, TALLOC_CTX *mem_ctx, 
			   union smb_fileinfo *io);
struct smb2_request *smb2_getinfo_fs_send(struct smb2_tree *tree, union smb_fsinfo *io);
NTSTATUS smb2_getinfo_fs_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx,
				union smb_fsinfo *io);
NTSTATUS smb2_getinfo_fs(struct smb2_tree *tree, TALLOC_CTX *mem_ctx, 
			   union smb_fsinfo *io);

/* The following definitions come from libcli/smb2/write.c  */

struct smb2_request *smb2_write_send(struct smb2_tree *tree, struct smb2_write *io);
NTSTATUS smb2_write_recv(struct smb2_request *req, struct smb2_write *io);
NTSTATUS smb2_write(struct smb2_tree *tree, struct smb2_write *io);

/* The following definitions come from libcli/smb2/read.c  */

struct smb2_request *smb2_read_send(struct smb2_tree *tree, struct smb2_read *io);
NTSTATUS smb2_read_recv(struct smb2_request *req, 
			TALLOC_CTX *mem_ctx, struct smb2_read *io);
NTSTATUS smb2_read(struct smb2_tree *tree, TALLOC_CTX *mem_ctx, struct smb2_read *io);

/* The following definitions come from libcli/smb2/setinfo.c  */

struct smb2_request *smb2_setinfo_send(struct smb2_tree *tree, struct smb2_setinfo *io);
NTSTATUS smb2_setinfo_recv(struct smb2_request *req);
NTSTATUS smb2_setinfo(struct smb2_tree *tree, struct smb2_setinfo *io);
struct smb2_request *smb2_setinfo_file_send(struct smb2_tree *tree, union smb_setfileinfo *io);
NTSTATUS smb2_setinfo_file(struct smb2_tree *tree, union smb_setfileinfo *io);

/* The following definitions come from libcli/smb2/find.c  */

struct smb2_request *smb2_find_send(struct smb2_tree *tree, struct smb2_find *io);
NTSTATUS smb2_find_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx,
			   struct smb2_find *io);
NTSTATUS smb2_find(struct smb2_tree *tree, TALLOC_CTX *mem_ctx,
		   struct smb2_find *io);
NTSTATUS smb2_find_level_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx,
			      uint8_t level, uint_t *count,
			      union smb_search_data **io);
NTSTATUS smb2_find_level(struct smb2_tree *tree, TALLOC_CTX *mem_ctx,
			 struct smb2_find *f, 
			 uint_t *count, union smb_search_data **io);

/* The following definitions come from libcli/smb2/ioctl.c  */

struct smb2_request *smb2_ioctl_send(struct smb2_tree *tree, struct smb2_ioctl *io);
NTSTATUS smb2_ioctl_recv(struct smb2_request *req, 
			 TALLOC_CTX *mem_ctx, struct smb2_ioctl *io);
NTSTATUS smb2_ioctl(struct smb2_tree *tree, TALLOC_CTX *mem_ctx, struct smb2_ioctl *io);

/* The following definitions come from libcli/smb2/logoff.c  */

struct smb2_request *smb2_logoff_send(struct smb2_session *session);
NTSTATUS smb2_logoff_recv(struct smb2_request *req);
NTSTATUS smb2_logoff(struct smb2_session *session);

/* The following definitions come from libcli/smb2/tdis.c  */

struct smb2_request *smb2_tdis_send(struct smb2_tree *tree);
NTSTATUS smb2_tdis_recv(struct smb2_request *req);
NTSTATUS smb2_tdis(struct smb2_tree *tree);

/* The following definitions come from libcli/smb2/flush.c  */

struct smb2_request *smb2_flush_send(struct smb2_tree *tree, struct smb2_flush *io);
NTSTATUS smb2_flush_recv(struct smb2_request *req, struct smb2_flush *io);
NTSTATUS smb2_flush(struct smb2_tree *tree, struct smb2_flush *io);

/* The following definitions come from libcli/smb2/lock.c  */

struct smb2_request *smb2_lock_send(struct smb2_tree *tree, struct smb2_lock *io);
NTSTATUS smb2_lock_recv(struct smb2_request *req, struct smb2_lock *io);
NTSTATUS smb2_lock(struct smb2_tree *tree, struct smb2_lock *io);

/* The following definitions come from libcli/smb2/notify.c  */

struct smb2_request *smb2_notify_send(struct smb2_tree *tree, struct smb2_notify *io);
NTSTATUS smb2_notify_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx,
			  struct smb2_notify *io);
NTSTATUS smb2_notify(struct smb2_tree *tree, TALLOC_CTX *mem_ctx,
		     struct smb2_notify *io);

/* The following definitions come from libcli/smb2/cancel.c  */

NTSTATUS smb2_cancel(struct smb2_request *r);

/* The following definitions come from libcli/smb2/keepalive.c  */

struct smb2_request *smb2_keepalive_send(struct smb2_transport *transport);
NTSTATUS smb2_keepalive_recv(struct smb2_request *req);
NTSTATUS smb2_keepalive(struct smb2_transport *transport);
#undef _PRINTF_ATTRIBUTE
#define _PRINTF_ATTRIBUTE(a1, a2)

#endif /* __LIBCLI_SMB2_SMB2_PROTO_H__ */

