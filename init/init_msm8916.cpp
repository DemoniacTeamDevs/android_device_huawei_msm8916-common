/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <fstream>
#include <string>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void vendor_load_properties()
{
    std::ifstream fin;
    std::string buf;

    std::string platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    fin.open("/proc/app_info");
    while (getline(fin, buf))
        if (buf.find("huawei_fac_product_name") != std::string::npos)
            break;
    fin.close();

    /* Y635-L01 */
    if (buf.find("Y635-L01") != std::string::npos) {
        property_set("ro.product.model", "Y635-L01");
        property_set("ro.product.name", "Y635-L01");
        property_set("ro.product.device", "Y635-L01");
        property_set("ro.build.product", "Y635-L01");
        property_set("ro.build.description", "Y635-L01-user 4.4.4 GRJ90 C21B131 release-keys");
        property_set("ro.build.fingerprint", "Huawei/Y635-L01/hwY635:4.4.4/HuaweiY635-L01/C21B131:user/release-keys");
	}
    /* Y635-L02 */
    else if (buf.find("Y635-L02") != std::string::npos) {
        property_set("ro.product.model", "Y635-L02");
        property_set("ro.product.name", "Y635-L02");
        property_set("ro.product.device", "Y635-L02");
        property_set("ro.build.product", "Y635-L02");
	}
    /* Y635-L03 */
    else if (buf.find("Y635-L03") != std::string::npos) {
        property_set("ro.product.model", "Y635-L03");
        property_set("ro.product.name", "Y635-L03");
        property_set("ro.product.device", "Y635-L03");
        property_set("ro.build.product", "Y635-L03");
        property_set("ro.build.description", "Y635-L03-user 4.4.4 GRJ90 C69B003 release-keys");
        property_set("ro.build.fingerprint", "Huawei/Y635-L03/hwY635:4.4.4/HuaweiY635-L03/C69B003:user/release-keys");
	}
    /* Y635-L11 */
    else if (buf.find("Y635-L11") != std::string::npos) {
        property_set("ro.product.model", "Y635-L11");
        property_set("ro.product.name", "Y635-L11");
        property_set("ro.product.device", "Y635-L11");
        property_set("ro.build.product", "Y635-L11");
	}
    /* Y635-L21 */
    else if (buf.find("Y635-L21") != std::string::npos) {
        property_set("ro.product.model", "Y635-L21");
        property_set("ro.product.name", "Y635-L21");
        property_set("ro.product.device", "Y635-L21");
        property_set("ro.build.product", "Y635-L21");
	}
}
