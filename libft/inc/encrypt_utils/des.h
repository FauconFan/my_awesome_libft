/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:46:05 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/19 14:24:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DES_H
#define DES_H

typedef enum			e_enc_action
{
	ENCRYPT,
	DECRYPT
}						t_enc_action;

typedef enum			e_enc_mode
{
	ECB,
	CBC,
	PCBC,
	CFB,
	OFB
}						t_enc_mode;

typedef struct			s_des
{
	uint64_t			key_n[16];
	uint64_t			key_n_rev[16];
	uint64_t			iv;
	t_enc_action		action;
	t_enc_mode			mode;
}						t_des;

t_des					*ft_des_new(
							uint64_t original_key,
							uint64_t iv,
							t_enc_action action,
							t_enc_mode mode);
void					ft_des_change_action(
							t_des *des,
							t_enc_action action);
void					ft_des_free();

uint64_t				ft_des_process_block(
							uint64_t msg,
							uint64_t keys[16]);

uint8_t					*ft_des_process(
							t_des *des,
							uint8_t *msg,
							size_t size_in,
							size_t *size_out);

uint8_t					*ft_des_ecb_enc(
							t_des *des,
							uint8_t *msg,
							size_t size);

uint8_t					*ft_des_ecb_dec(
							t_des *des,
							uint8_t *msg,
							size_t size);

uint8_t					*ft_des_cbc_enc(
							t_des *des,
							uint8_t *msg,
							size_t size);

uint8_t					*ft_des_cbc_dec(
							t_des *des,
							uint8_t *msg,
							size_t size);

uint8_t					*ft_des_pcbc_enc(
							t_des *des,
							uint8_t *msg,
							size_t size);

uint8_t					*ft_des_pcbc_dec(
							t_des *des,
							uint8_t *msg,
							size_t size);

uint8_t					*ft_des_cfb_enc(
							t_des *des,
							uint8_t *msg,
							size_t size);

uint8_t					*ft_des_cfb_dec(
							t_des *des,
							uint8_t *msg,
							size_t size);

uint8_t					*ft_des_ofb_enc(
							t_des *des,
							uint8_t *msg,
							size_t size);

uint8_t					*ft_des_ofb_dec(
							t_des *des,
							uint8_t *msg,
							size_t size);

uint32_t				ft_des_apply_pc1_left(uint64_t original_key);
uint32_t				ft_des_apply_pc1_right(uint64_t original_key);
uint64_t				ft_des_apply_pc2(uint64_t l, uint64_t r);
uint64_t				ft_des_apply_e(uint32_t r);
uint32_t				ft_des_apply_p(uint32_t u);
uint32_t				ft_des_apply_s_tables(uint64_t u);
uint64_t				ft_des_apply_ip(uint64_t u);
uint64_t				ft_des_apply_ip_min1(uint64_t u);

void					ft_des_append_padding(uint8_t *msg, size_t remain);

uint64_t				ft_des_build_msg(uint8_t *msg);
void					ft_des_save_msg(uint8_t *res, uint64_t out);

extern uint8_t			g_des_pc1_left[28];
extern uint8_t			g_des_pc1_right[28];
extern uint8_t			g_des_shifts_subkeys[16];
extern uint8_t			g_des_pc2[48];
extern uint8_t			g_des_ip[64];
extern uint8_t			g_des_ip_min1[64];
extern uint8_t			g_des_e[48];
extern uint8_t			g_des_p[32];
extern uint8_t			*g_des_s_tables[8];

#endif
