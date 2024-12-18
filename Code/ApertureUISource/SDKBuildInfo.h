/*
This code is part of Aperture UI - A HTML/CSS/JS UI Middleware

Copyright (c) 2020-2024 WD Studios L.L.C. and/or its licensors. All
rights reserved in all media.

The coded instructions, statements, computer programs, and/or related
material (collectively the "Data") in these files contain confidential
and unpublished information proprietary WD Studios and/or its
licensors, which is protected by United States of America federal
copyright law and by international treaties.

This software or source code is supplied under the terms of a license
agreement and nondisclosure agreement with WD Studios L.L.C. and may
not be copied, disclosed, or exploited except in accordance with the
terms of that agreement. The Data may not be disclosed or distributed to
third parties, in whole or in part, without the prior written consent of
WD Studios L.L.C..

WD STUDIOS MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS
SOURCE CODE FOR ANY PURPOSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER, ITS AFFILIATES,
PARENT COMPANIES, LICENSORS, SUPPLIERS, OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OR PERFORMANCE OF THIS SOFTWARE OR SOURCE CODE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#define NS_GIT_COMMIT_HASH_SHORT 3632b4c23aa5
#define NS_GIT_COMMIT_HASH_LONG 3632b4c23aa58e803055e60d0da5a9cc91001942
#define NS_GIT_BRANCH_NAME "engine-rewrite-iscriping-engine"

// NOTE(Mikael A.): Add APUI ending for naming rule. 
#define APUI_GIT_COMMIT_HASH_SHORT NS_GIT_COMMIT_HASH_SHORT
#define APUI_GIT_COMMIT_HASH_LONG NS_GIT_COMMIT_HASH_LONG
#define APUI_GIT_BRANCH_NAME NS_GIT_BRANCH_NAME

// NOTE(Mikael A.): SDK Version. Format: Year.Month.BuildIndex.Patch, Just like O3DE.
#define APUI_SDK_VERSION_MAJOR 24
#define APUI_SDK_VERSION_MINOR 12
#define APUI_SDK_VERSION_BUILD 1
#define APUI_SDK_VERSION_PATCH 0

#define APUI_SDK_VERSION_STRING "ApertureUI SDK Version: " APUI_SDK_VERSION_MAJOR "." APUI_SDK_VERSION_MINOR "." APUI_SDK_VERSION_BUILD "." APUI_SDK_VERSION_PATCH
#define APUI_SDK_VERSION_STRING_SHORT "ApertureUI SDK Version: " APUI_SDK_VERSION_MAJOR "." APUI_SDK_VERSION_MINOR "." APUI_SDK_VERSION_BUILD
#define APUI_SDK_VERSION APUI_SDK_VERSION_MAJOR "." APUI_SDK_VERSION_MINOR "." APUI_SDK_VERSION_BUILD "." APUI_SDK_VERSION_PATCH