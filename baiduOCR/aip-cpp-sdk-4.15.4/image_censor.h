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

    class Imagecensor: public AipBase
    {
    public:

    
        std::string _anti_porn =
            "https://aip.baidubce.com/rest/2.0/antiporn/v1/detect";
        
        std::string _anti_porn_gif =
            "https://aip.baidubce.com/rest/2.0/antiporn/v1/detect_gif";
        
        std::string _anti_terror =
            "https://aip.baidubce.com/rest/2.0/antiterror/v1/detect";
        

        Imagecensor(const std::string & app_id, const std::string & ak, const std::string & sk): AipBase(app_id, ak, sk)
        {
        }
        
        /**
         * anti_porn
         * 该请求用于鉴定图片的色情度。即对于输入的一张图片（可正常解码，且长宽比适宜），输出图片的色情度。目前支持三个维度：色情、性感、正常。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         */
        Json::Value anti_porn(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_anti_porn, null, data, null);

            return result;
        }
        
        /**
         * anti_porn_gif
         * 该请求用于鉴定GIF图片的色情度，对于非gif接口，请使用色情识别接口。接口会对图片中每一帧进行识别，并返回所有检测结果中色情值最大的为结果。目前支持三个维度：色情、性感、正常。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         */
        Json::Value anti_porn_gif(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_anti_porn_gif, null, data, null);

            return result;
        }
        
        /**
         * anti_terror
         * 该请求用于鉴定图片是否涉暴涉恐。即对于输入的一张图片（可正常解码，且长宽比适宜），输出图片的涉暴涉恐程度。
         * @param image 图像文件二进制内容，可以使用aip::get_file_content函数获取
         * options 可选参数:
         */
        Json::Value anti_terror(
            std::string const & image,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            
            data["image"] = base64_encode(image.c_str(), (int) image.size());

            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));

            Json::Value result =
                this->request(_anti_terror, null, data, null);

            return result;
        }
        

    };
}
#endif