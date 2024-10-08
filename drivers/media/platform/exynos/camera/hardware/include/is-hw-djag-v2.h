/*
 * Samsung Exynos SoC series Pablo driver
 *
 * Copyright (c) 2019 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef IS_HW_DJAG_H
#define IS_HW_DJAG_H

/* for DeJag Block */
#define MCSC_DJAG_PRESCALE_INDEX_1		0	/* x1.0 */
#define MCSC_DJAG_PRESCALE_INDEX_2		1	/* x1.1~x1.4 */
#define MCSC_DJAG_PRESCALE_INDEX_3		2	/* x1.5~x2.0 */
#define MCSC_DJAG_PRESCALE_INDEX_4		3	/* x2.1~ */

#define MAX_SCALINGRATIOINDEX_DEPENDED_CONFIGS	(4)
#define MAX_DITHER_VALUE_CONFIGS				(9)

struct djag_xfilter_dejagging_coeff_config {
	u32 xfilter_dejagging_weight0;
	u32 xfilter_dejagging_weight1;
	u32 xfilter_hf_boost_weight;
	u32 center_hf_boost_weight;
	u32 diagonal_hf_boost_weight;
	u32 center_weighted_mean_weight;
};

struct djag_thres_1x5_matching_config {
	u32 thres_1x5_matching_sad;
	u32 thres_1x5_abshf;
};

struct djag_thres_shooting_detect_config {
	u32 thres_shooting_llcrr;
	u32 thres_shooting_lcr;
	u32 thres_shooting_neighbor;
	u32 thres_shooting_uucdd;
	u32 thres_shooting_ucd;
	u32 min_max_weight;
};

struct djag_lfsr_seed_config {
	u32 lfsr_seed_0;
	u32 lfsr_seed_1;
	u32 lfsr_seed_2;
};

struct djag_dither_config {
	u32 dither_value[MAX_DITHER_VALUE_CONFIGS];
	u32 sat_ctrl;
	u32 dither_sat_thres;
	u32 dither_thres;
};

struct djag_cp_config {
	u32 cp_hf_thres;
	u32 cp_arbi_max_cov_offset;
	u32 cp_arbi_max_cov_shift;
	u32 cp_arbi_denom;
	u32 cp_arbi_mode;
};

struct djag_harris_det_config {
	u32 harris_k;
	u32 harris_th;
};

struct djag_harris_bilateral_c_config {
	u32 bilateral_c;
};

#if IS_ENABLED(USE_DJAG_COEFF_CONFIG)
struct djag_sc_h_coef_cfg {
	int h_coef_a[9];
	int h_coef_b[9];
	int h_coef_c[9];
	int h_coef_d[9];
	int h_coef_e[9];
	int h_coef_f[9];
	int h_coef_g[9];
	int h_coef_h[9];
};

struct djag_sc_v_coef_cfg {
	int v_coef_a[9];
	int v_coef_b[9];
	int v_coef_c[9];
	int v_coef_d[9];
};

struct djag_coef_cfg {
	bool use_djag_sc_coef;	/* 0 : default, 1 : use djag_sc_h_coef/djag_sc_v_coef */
	struct djag_sc_h_coef_cfg djag_sc_h_coef;
	struct djag_sc_v_coef_cfg djag_sc_v_coef;
};
#endif

struct predjag_scaling_ratio_depended_config {
	struct djag_xfilter_dejagging_coeff_config xfilter_dejagging_coeff_cfg;
	struct djag_thres_1x5_matching_config thres_1x5_matching_cfg;
	struct djag_thres_shooting_detect_config thres_shooting_detect_cfg;
	struct djag_lfsr_seed_config lfsr_seed_cfg;
	struct djag_dither_config dither_cfg;
	struct djag_cp_config cp_cfg;
	struct djag_harris_det_config harris_det_cfg;
	struct djag_harris_bilateral_c_config bilateral_c_cfg;
};

struct djag_scaling_ratio_depended_config {
	struct djag_xfilter_dejagging_coeff_config xfilter_dejagging_coeff_cfg;
	struct djag_thres_1x5_matching_config thres_1x5_matching_cfg;
	struct djag_thres_shooting_detect_config thres_shooting_detect_cfg;
	struct djag_lfsr_seed_config lfsr_seed_cfg;
	struct djag_dither_config dither_cfg;
	struct djag_cp_config cp_cfg;
#if IS_ENABLED(USE_DJAG_COEFF_CONFIG)
	struct djag_coef_cfg djag_sc_coef;
#endif
};

struct predjag_setfile_contents {
	bool djag_en;
	struct predjag_scaling_ratio_depended_config
	scaling_ratio_depended_cfg[MAX_SCALINGRATIOINDEX_DEPENDED_CONFIGS];
};

struct djag_setfile_contents {
	bool djag_en;
	struct djag_scaling_ratio_depended_config
	scaling_ratio_depended_cfg[MAX_SCALINGRATIOINDEX_DEPENDED_CONFIGS];
};

struct djag_wb_thres_cfg {
	u32 dither_wb_thres;
};
#endif
