"""scripts/check_repo.py passes on the repository (the same check CI runs)."""
import check_repo


def test_repository_is_consistent(capsys):
    assert check_repo.main() == 0, capsys.readouterr().out


def test_queue_seed_data_is_tracked_and_valid():
    """A fresh download builds the same work queue as an old copy only if these seed files are present."""
    import queue_builder as Q
    from conftest import ROOT
    seeds = Q.seed_data(ROOT)
    assert len(seeds["known_functions"]) > 1000
    starts = seeds["extra_starts"]
    assert set(starts) <= {"pc", "xb", "proto"} and sum(len(v) for v in starts.values()) > 900
    for vas in starts.values():
        assert all(len(v) == 10 and int(v, 16) > 0 for v in vas) and vas == sorted(set(vas))
