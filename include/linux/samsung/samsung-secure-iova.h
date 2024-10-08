// SPDX-License-Identifier: GPL-2.0
/*
 * Samsung IOVA Management header
 *
 * Copyright (c) 2021 Samsung Electronics Co., Ltd.
 * Author: <hyesoo.yu@samsung.com> for Samsung
 */

#if IS_ENABLED(CONFIG_EXYNOS_CONTENT_PATH_PROTECTION)
unsigned long secure_iova_alloc(unsigned long size, unsigned int align);
void secure_iova_free(unsigned long addr, unsigned long size);
#else
unsigned long secure_iova_alloc(unsigned long size, unsigned int align)
{
	pr_err("%s: CONTENT_PATH_PROTECTION is disabled, failed to alloc.\n", __func__);
	return 0;
}
void secure_iova_free(unsigned long addr, unsigned long size) { }
#endif
