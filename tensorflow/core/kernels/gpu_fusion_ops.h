/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_KERNELS_GPU_FUSION_OPS_H_
#define TENSORFLOW_KERNELS_GPU_FUSION_OPS_H_

#ifdef TENSORFLOW_USE_ROCM

#include "tensorflow/core/framework/op_kernel.h"
#include "tensorflow/core/platform/stream_executor.h"
#include "tensorflow/core/util/activation_mode.h"

namespace tensorflow {

se::dnn::ActivationMode GetDnnActivationMode(ActivationMode activation_mode);

namespace rocm_kernels {

void FusionAddRelu(OpKernelContext* ctx, const float* in0, const float* in1,
                   float* out, unsigned N);

void FusionAddRelu(OpKernelContext* ctx, const Eigen::half* in0,
                   const Eigen::half* in1, Eigen::half* out, unsigned N);

void FusionAddNReluGrad(OpKernelContext* ctx, const float* in0,
                        const float* in1, const float* in2, float* out,
                        unsigned N);

void FusionAddNReluGrad(OpKernelContext* ctx, const Eigen::half* in0,
                        const Eigen::half* in1, const Eigen::half* in2,
                        Eigen::half* out, unsigned N);

}  // namespace rocm_kernels

}  // namespace tensorflow

#endif  // TENSORFLOW_USE_ROCM

#endif  // TENSORFLOW_KERNELS_GPU_FUSION_OPS_H_
