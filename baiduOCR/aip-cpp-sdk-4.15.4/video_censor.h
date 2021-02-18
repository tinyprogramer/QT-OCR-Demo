/**
 * Copyright (c) 2017 Baidu.com, Inc. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on
 * an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations under the License.
 *
 * @author baidu aip
 */

#ifndef __AIP_IMAGECENSOR_H__
#define __AIP_IMAGECENSOR_H__

#include "base/base.h"

namespace aip {

    class Videoecensor: public AipBase
    {
    public:

    
        std::string _videoe_url =
            "https://aip.baidubce.com/rest/2.0/solution/v1/video_censor/v2/user_defined";
        

        Videocensor(const std::string & app_id, const std::string & ak, const std::string & sk): AipBase(app_id, ak, sk)
        {
        }
        
        /**
         * voice_censor
         *  本接口除了支持自定义配置外，还对返回结果进行了总体的包装，按照用户在控制台中配置的规则直接返回是否合规，如果不合规则指出具体不合规的内容。
         * @param voice 语音文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         */
        Json::Value video_censor(
            std::string const & name,
            std::string const & url,
            std::string const & extId,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["videoUrl"] = url;
            data["name"] = name;
            data["extId"] = extId;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_voice_url, null, data, null);

            return result;
        }
  
    };
}
#endif
