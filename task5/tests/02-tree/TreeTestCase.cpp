//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <boost/filesystem.hpp>

boost::filesystem::path TreeTestCase::dir;

void TreeTestCase::SetUpTestCase() {
    dir = boost::filesystem::unique_path();
    boost::filesystem::create_directory(dir);
    boost::filesystem::create_directory(dir / "dop_dir");
    boost::filesystem::ofstream file(dir / "file");
    file.close();
}

void TreeTestCase::TearDownTestCase() {
    boost::filesystem::remove_all(dir);
}

TEST_F(TreeTestCase, first_exeption) {
    ASSERT_THROW(GetTree("hoi/hoi/hoi", true), std::invalid_argument);
}

TEST_F(TreeTestCase, second_exeption) {
    ASSERT_THROW(GetTree(TreeTestCase::dir.string() + "/file", true), std::invalid_argument);
}

TEST_F(TreeTestCase, quantity) {
    FileNode res = GetTree(TreeTestCase::dir.string(), true);
    FileNode result = GetTree(TreeTestCase::dir.string(), false);
}

TEST_F(TreeTestCase, equally) {
    ASSERT_EQ(GetTree(TreeTestCase::dir.string(), true), GetTree(TreeTestCase::dir.string(), true));
}